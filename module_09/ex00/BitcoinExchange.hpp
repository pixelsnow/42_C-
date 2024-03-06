#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <chrono>
/* 
#include <ctime>
#include <iomanip>
 */

class BitcoinExchange
{
private:
	std::map<std::string,double> rates;
	
	bool dateValid(const std::string &dateStr) const;
	bool dateValid(const std::string &dateStr, const std::string &valueStr) const;
	double getExchangeRate(const std::string &dateStr) const;
	void displayLine(const std::string &line) const;

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & source);
	BitcoinExchange(std::fstream &db);
	~BitcoinExchange();

	BitcoinExchange & operator=(BitcoinExchange const & source);

	void displayConversions(std::fstream &input) const;
	
	class NoConversion : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

#endif
