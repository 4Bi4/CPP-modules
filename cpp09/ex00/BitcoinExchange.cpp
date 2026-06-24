#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_db = other._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s)
{
	size_t start = 0;
	size_t end   = s.size();
	while (start < end && std::isspace(static_cast<unsigned char>(s[start])))
		++start;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		--end;
	return (s.substr(start, end - start));
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());
	return (month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

bool BitcoinExchange::parseValue(const std::string &str, double &out)
{
	if (str.empty())
		return (false);
	char *end;
	out = std::strtod(str.c_str(), &end);
	while (*end == ' ' || *end == '\t')
		++end;
	if (*end != '\0' && *end != '\n')
		return (false);
	return (true);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue ;

		std::string date  = trim(line.substr(0, comma));
		std::string value = trim(line.substr(comma + 1));

		double rate;
		if (!isValidDate(date) || !parseValue(value, rate))
			continue ;
		_db[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string date     = trim(line.substr(0, sep));
		std::string valueStr = trim(line.substr(sep + 3));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		double value;
		if (!parseValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		std::map<std::string, double>::const_iterator it = _db.upper_bound(date);
		if (it == _db.begin())
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		it--;

		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}
