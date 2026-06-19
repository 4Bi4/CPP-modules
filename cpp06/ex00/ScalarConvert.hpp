#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>

class ScalarConvert
{
public:
	ScalarConvert(const ScalarConvert &other);
	ScalarConvert &operator=(const ScalarConvert &other);
	~ScalarConvert();

	static void convert(const std::string &input);

private:
	ScalarConvert();

	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isPseudoFloat(const std::string &input);
	static bool isPseudoDouble(const std::string &input);

	static void convertToChar(double value);
	static void convertToInt(double value);
	static void convertToFloat(double value);
	static void convertToDouble(double value);
};

#endif
