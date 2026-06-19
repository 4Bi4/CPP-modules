#include <iostream>
#include <string>
#include "whatever.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << s << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	title("TESTING WITH INTEGERS");
	{
		int a = 2;
		int b = 3;
		std::cout << "before: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}

	title("TESTING WITH DOUBLES");
	{
		double a = 1.5;
		double b = 2.7;
		std::cout << "before: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}

	title("TESTING WITH STRINGS");
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "before: c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after swap: c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}

	title("TESTING EQUAL VALUES (returns second)");
	{
		int a = 42;
		int b = 42;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) returns second: " << (&::min(a, b) == &b ? "yes" : "no") << std::endl;
		std::cout << "max(a, b) returns second: " << (&::max(a, b) == &b ? "yes" : "no") << std::endl;
	}

	title("TESTING WITH CHARS");
	{
		char a = 'z';
		char b = 'a';
		std::cout << "before: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}

	return (0);
}
