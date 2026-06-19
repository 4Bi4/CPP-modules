#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << s << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
}

template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
}

void increment(int &x)
{
	++x;
}

void toUpper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void printDouble(double const &x)
{
	std::cout << x * 2.0 << " ";
}

int main(void)
{
	title("TESTING WITH INT ARRAY");
	{
		int arr[] = {1, 2, 3, 4, 5};
		size_t len = 5;

		std::cout << "initial:   "; ::iter(arr, len, print<int>); std::cout << std::endl;
		::iter(arr, len, increment);
		std::cout << "after ++:  "; ::iter(arr, len, print<int>); std::cout << std::endl;
	}

	title("TESTING WITH CONST INT ARRAY");
	{
		const int arr[] = {10, 20, 30, 40, 50};
		size_t len = 5;

		std::cout << "elements: "; ::iter(arr, len, print<int>); std::cout << std::endl;
	}

	title("TESTING WITH CHAR ARRAY");
	{
		char arr[] = {'h', 'e', 'l', 'l', 'o'};
		size_t len = 5;

		std::cout << "before toUpper: "; ::iter(arr, len, print<char>); std::cout << std::endl;
		::iter(arr, len, toUpper);
		std::cout << "after toUpper:  "; ::iter(arr, len, print<char>); std::cout << std::endl;
	}

	title("TESTING WITH DOUBLE ARRAY");
	{
		double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t len = 5;

		std::cout << "values:   "; ::iter(arr, len, print<double>); std::cout << std::endl;
		std::cout << "doubled:  "; ::iter(arr, len, printDouble);   std::cout << std::endl;
	}

	title("TESTING WITH STRING ARRAY");
	{
		std::string arr[] = {"foo", "bar", "baz"};
		size_t len = 3;

		std::cout << "strings: "; ::iter(arr, len, print<std::string>); std::cout << std::endl;
	}

	title("TESTING WITH EMPTY ARRAY");
	{
		int arr[] = {42};
		std::cout << "iter on 0 elements (no output): ";
		::iter(arr, 0, print<int>);
		std::cout << "(done)" << std::endl;
	}

	return (0);
}
