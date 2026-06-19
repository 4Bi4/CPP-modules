#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << s << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
}

template <typename T>
static void printArray(const std::string &label, Array<T> &arr)
{
	std::cout << label << " (size=" << arr.size() << "): ";
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	title("TESTING DEFAULT CONSTRUCTOR");
	{
		Array<int> empty;
		std::cout << "Array<int>(): size = " << empty.size() << std::endl;
	}

	title("TESTING SIZE CONSTRUCTOR (value-initialized)");
	{
		Array<int> ints(5);
		printArray("Array<int>(5)", ints);

		Array<double> dbls(3);
		printArray("Array<double>(3)", dbls);
	}

	title("TESTING ELEMENT ACCESS AND MODIFICATION");
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = static_cast<int>(i * 10);
		printArray("after fill", arr);
	}

	title("TESTING COPY CONSTRUCTOR (independent copy)");
	{
		Array<int> original(3);
		original[0] = 10;
		original[1] = 20;
		original[2] = 30;

		Array<int> copy(original);
		copy[0] = 99;

		printArray("original (unchanged)", original);
		printArray("copy (modified [0])", copy);
	}

	title("TESTING ASSIGNMENT OPERATOR (independent copy)");
	{
		Array<int> a(3);
		a[0] = 1; a[1] = 2; a[2] = 3;

		Array<int> b(3);
		b[0] = 4; b[1] = 5; b[2] = 6;

		b = a;
		b[0] = 99;

		printArray("a (unchanged after b = a; b[0] = 99)", a);
		printArray("b (modified)", b);
	}

	title("TESTING SELF-ASSIGNMENT");
	{
		Array<int> arr(3);
		arr[0] = 7; arr[1] = 8; arr[2] = 9;
		arr = arr;
		printArray("after self-assignment", arr);
	}

	title("TESTING OUT OF BOUNDS EXCEPTION");
	{
		Array<int> arr(3);

		std::cout << "--- access index 3 on size-3 array ---" << std::endl;
		try { std::cout << arr[3] << std::endl; }
		catch (std::exception &e) { std::cout << "caught: " << e.what() << std::endl; }

		std::cout << "--- access index 100 ---" << std::endl;
		try { std::cout << arr[100] << std::endl; }
		catch (std::exception &e) { std::cout << "caught: " << e.what() << std::endl; }

		std::cout << "--- access index 0 on empty array ---" << std::endl;
		Array<int> empty;
		try { std::cout << empty[0] << std::endl; }
		catch (std::exception &e) { std::cout << "caught: " << e.what() << std::endl; }
		std::cout << std::endl;
	}

	title("TESTING WITH STRINGS");
	{
		Array<std::string> strs(3);
		strs[0] = "hello";
		strs[1] = "world";
		strs[2] = "!";
		printArray("Array<string>(3)", strs);

		Array<std::string> copy(strs);
		copy[0] = "bye";
		printArray("original (unchanged)", strs);
		printArray("copy (modified [0])", copy);
	}

	return (0);
}
