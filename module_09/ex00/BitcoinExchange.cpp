#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & source)
{
	this->rates = source.rates;
}

BitcoinExchange::BitcoinExchange(std::fstream &db)
{
	// Skip header line
	std::string line;
	std::getline(db, line);

	while (std::getline(db, line))
	{
		size_t pos = line.find(',');
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		double rate = stod(rateStr);
		this->rates[date] = rate;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & source)
{
	this->rates = source.rates;
	return *this;
}

bool BitcoinExchange::dateValid(const std::string &dateStr) const
{
	// will be used to store broken down date components
	std::tm tm = {};
	// allows the date to be read as if it were a stream of input,
	// which is necessary for the std::get_time to parse the date string
	std::istringstream ss(dateStr);

	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
	{
		return false;
	}
	// A copy to compare the values to after date normalization
	std::tm tm_copy = tm;

	// time_t - time in second since the epoch
	// mktime() normalizes the tm structure and checks if the date is valid.
	// If the date is valid, mktime() will return a non-negative time_t value.
	std::time_t tt = std::mktime(&tm);
	if (tt == -1) {
		return false;
	}

	// If the date string was "2023-13-32", for example, std::mktime would normalize it to "2024-01-01", which we want to catch
	if ((tm.tm_year != tm_copy.tm_year ||
		tm.tm_mon != tm_copy.tm_mon ||
		tm.tm_mday != tm_copy.tm_mday))
	{
		return false;
	}

	return true;
}

double BitcoinExchange::getExchangeRate(const std::string &dateStr) const
{
	std::map<std::string,double>::const_iterator it;
	it = this->rates.lower_bound(dateStr);
	if (it == this->rates.begin() && it->first != dateStr)
	{
		throw NoConversion();
	}
	return it->second;
}

void BitcoinExchange::displayConversions(std::fstream &input) const
{
	std::string line;
	std::regex inputFormat("^(\\d{4}-\\d{2}-\\d{2}) \\| ([-+]?\\d*\\.?\\d+)$");
	std::smatch matches;

	// Skip header line
	std::getline(input, line);

	while (std::getline(input, line)) {
		// Validate the line against regex
		if (!std::regex_match(line, matches, inputFormat))
		{
			std::cout << "ERROR: Bad input => " << line << std::endl;
			continue;
		}
		// Validate date
		if (!this->dateValid(matches[1]))
		{
			std::cout << "ERROR: Invalid date => " << matches[1] << std::endl;
			continue;
		}
		// Validate value
		// Convert value to float
		float value;
		try
		{
			value = std::stof(matches[2]);
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "ERROR: Invalid value => " << matches[2] << std::endl;
		}
		catch(const std::out_of_range& e)
		{
			std::cout << "ERROR: Value out of range => " << matches[2] << std::endl;
		}
		// Check that value is between 0 and 1000
		if (value < 0)
		{
			std::cout << "ERROR: Value negative => " << matches[2] << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "ERROR: Value too large => " << matches[2] << std::endl;
			continue;
		}
		
		// SUCCESS case
		double rate;
		try
		{
			rate = this->getExchangeRate(matches[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << "ERROR: No bitcoin conversion rate for the date => " << matches[1] << std::endl;
			continue;
		}
		
		std::cout << matches[1] << " => " << value << " = " << value * rate << std::endl;
	}
}

const char * BitcoinExchange::NoConversion::what() const throw()
{
	return "ERROR: No bitcoin conversion rate for this date";
}
