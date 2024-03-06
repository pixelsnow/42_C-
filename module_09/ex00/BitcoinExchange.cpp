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
	if (tt == -1)
	{
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
	if (it->first == dateStr)
	{
		return it->second;
	}
	else if (it == this->rates.begin())
	{
		throw NoConversion();
	}
	return prev(it)->second;
}

void BitcoinExchange::displayError(const std::string &message,
	const std::string &value) const
{
	std::cout << RED << "ERROR: " << message << BLUE << " => " << RESET << value << std::endl;
}

void BitcoinExchange::displayMatchedLine(const std::string &dateMatch,
	const std::string &valueMatch) const
{
	// Validate date
	if (!this->dateValid(dateMatch))
	{
		return (displayError("Invalid date", dateMatch));
	}
	// Validate value and convert it to float
	float value;
	try
	{
		value = std::stof(valueMatch);
	}
	catch(const std::exception& e)
	{
		return (displayError("Value not a valid float number", valueMatch));
	}
	if (value < 0)
	{
		return (displayError("Value negative", valueMatch));
	}
	if (value > 1000)
	{
		return (displayError("Value too large", valueMatch));
	}
	// If date and value are valid, calculate rate
	double rate;
	try
	{
		rate = this->getExchangeRate(dateMatch);
	}
	catch(const std::exception& e)
	{
		return (displayError("There's no exchange rate data for this date", dateMatch));
	}
	std::cout << dateMatch << BLUE << " => " << RESET << value << BLUE << " = " << RESET << value * rate << std::endl;
}

void BitcoinExchange::displayLine(const std::string &line) const
{
	std::regex inputFormat("^(\\d{4}-\\d{2}-\\d{2}) \\| ([-+]?\\d*\\.?\\d+)$");
	std::smatch matches;
	if (!std::regex_match(line, matches, inputFormat))
	{
		return (displayError("Bad input", line));
	}
	displayMatchedLine(matches[1], matches[2]);
}

void BitcoinExchange::displayConversions(std::fstream &input) const
{
	std::string line;

	std::getline(input, line);
	if (line != "date | value")
	{
		displayError("Even your header is bullshit", line);
	}
	while (std::getline(input, line))
	{
		this->displayLine(line);
	}
}

const char * BitcoinExchange::NoConversion::what() const throw()
{
	return "No bitcoin conversion rate for this date";
}
