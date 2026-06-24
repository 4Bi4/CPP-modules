#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename) const;

private:
	std::map<std::string, double> _db;

	static bool   isValidDate(const std::string &date);
	static bool   parseValue(const std::string &str, double &out);
	static std::string trim(const std::string &s);
};

#endif
