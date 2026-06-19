#include "ScalarConvert.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const ScalarConvert &other)
{
	(void)other;
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &other)
{
	(void)other;
	return (*this);
}

ScalarConvert::~ScalarConvert() {}

bool ScalarConvert::isChar(const std::string &input)
{
	return (input.length() == 1 && std::isprint(static_cast<unsigned char>(input[0])));
}

bool ScalarConvert::isInt(const std::string &input)
{
	if (input.empty())
		return (false);

	size_t start = 0;
	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start == input.length())
		return (false);

	for (size_t i = start; i < input.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (false);
	}
	return (true);
}

bool ScalarConvert::isFloat(const std::string &input)
{
	if (input.empty() || input[input.length() - 1] != 'f')
		return (false);

	size_t start = 0;
	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start >= input.length() - 1)
		return (false);

	bool hasDecimalPoint = false;
	for (size_t i = start; i < input.length() - 1; ++i)
	{
		if (input[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (false);
	}
	return (hasDecimalPoint);
}

bool ScalarConvert::isDouble(const std::string &input)
{
	if (input.empty())
		return (false);

	size_t start = 0;
	if (input[0] == '-' || input[0] == '+')
		start = 1;
	if (start == input.length())
		return (false);

	bool hasDecimalPoint = false;
	for (size_t i = start; i < input.length(); ++i)
	{
		if (input[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (false);
	}
	return (hasDecimalPoint);
}

bool ScalarConvert::isPseudoFloat(const std::string &input)
{
	return (input == "nanf" || input == "+inff" || input == "-inff");
}

bool ScalarConvert::isPseudoDouble(const std::string &input)
{
	return (input == "nan" || input == "+inf" || input == "-inf");
}

void ScalarConvert::convertToChar(double value)
{
	if (value != value
		|| value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity()
		|| value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConvert::convertToInt(double value)
{
	if (value != value
		|| value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity()
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConvert::convertToFloat(double value)
{
	if (value != value)
		std::cout << "float: nanf" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (value < -static_cast<double>(std::numeric_limits<float>::max())
		|| value > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
				  << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConvert::convertToDouble(double value)
{
	if (value != value)
		std::cout << "double: nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConvert::convert(const std::string &input)
{
	double value;

	if (isPseudoFloat(input) || isPseudoDouble(input))
	{
		if (input == "nan" || input == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inf" || input == "+inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	else if (isInt(input))
		value = std::strtod(input.c_str(), NULL);
	else if (isFloat(input))
		value = static_cast<double>(std::atof(input.c_str()));
	else if (isDouble(input))
		value = std::strtod(input.c_str(), NULL);
	else if (isChar(input))
		value = static_cast<double>(static_cast<unsigned char>(input[0]));
	else
	{
		std::cout << "Error: Invalid input" << std::endl;
		return ;
	}

	convertToChar(value);
	convertToInt(value);
	convertToFloat(value);
	convertToDouble(value);
}
