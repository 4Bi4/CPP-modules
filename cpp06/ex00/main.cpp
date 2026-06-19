#include <iostream>
#include "ScalarConvert.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << s << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
}

static void run(const std::string &label, const std::string &input)
{
	std::cout << "--- " << label << " (\"" << input << "\") ---" << std::endl;
	ScalarConvert::convert(input);
	std::cout << std::endl;
}

int main(void)
{
	title("TESTING CHAR");
	run("letter 'a'", "a");
	run("space",      " ");
	run("tilde '~'",  "~");
	run("bang '!'",   "!");

	title("TESTING INT");
	run("zero",    "0");
	run("positive","42");
	run("negative","-42");

	title("TESTING FLOAT");
	run("zero",     "0.0f");
	run("positive", "3.14f");
	run("negative", "-4.2f");

	title("TESTING DOUBLE");
	run("zero",     "0.0");
	run("positive", "3.14");
	run("negative", "-4.2");

	title("TESTING EDGE CASES");
	run("INT_MAX", "2147483647");
	run("INT_MIN", "-2147483648");
	run("large double (out of int range)", "99999999999.0");

	title("TESTING IMPOSSIBLE CASES");
	run("negative (impossible char/float)", "-1.0");
	run("value above 127 (impossible char)", "200.0");

	title("TESTING PSEUDO-LITERALS");
	run("nan",   "nan");
	run("+inf",  "+inf");
	run("-inf",  "-inf");
	run("nanf",  "nanf");
	run("+inff", "+inff");
	run("-inff", "-inff");

	title("TESTING INVALID INPUTS");
	run("empty string", "");
	run("letters",      "abc");
	run("1.2.3",        "1.2.3");
	run("1.2f3",        "1.2f3");
	run("sci notation", "1e10");

	return (0);
}
