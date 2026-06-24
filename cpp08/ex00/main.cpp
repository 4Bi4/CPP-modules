#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

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
	title("TESTING WITH std::vector<int>");
	{
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		v.push_back(50);

		try
		{
			std::vector<int>::iterator it = easyfind(v, 30);
			std::cout << "found 30 at index " << (it - v.begin()) << std::endl;
		}
		catch (std::exception &e) { std::cout << "30 not found: " << e.what() << std::endl; }

		try
		{
			std::vector<int>::iterator it = easyfind(v, 10);
			std::cout << "found 10 at index " << (it - v.begin()) << std::endl;
		}
		catch (std::exception &e) { std::cout << "10 not found: " << e.what() << std::endl; }

		try
		{
			std::vector<int>::iterator it = easyfind(v, 99);
			std::cout << "found 99 at index " << (it - v.begin()) << std::endl;
		}
		catch (std::exception &e) { std::cout << "99 not found: " << e.what() << std::endl; }
	}

	title("TESTING WITH std::list<int>");
	{
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);

		try
		{
			std::list<int>::iterator it = easyfind(l, 2);
			std::cout << "found: " << *it << std::endl;
		}
		catch (std::exception &e) { std::cout << "2 not found: " << e.what() << std::endl; }

		try
		{
			easyfind(l, 42);
			std::cout << "found: 42" << std::endl;
		}
		catch (std::exception &e) { std::cout << "42 not found: " << e.what() << std::endl; }
	}

	title("TESTING WITH std::deque<int>");
	{
		std::deque<int> d;
		d.push_back(100);
		d.push_back(200);
		d.push_back(300);

		try
		{
			std::deque<int>::iterator it = easyfind(d, 200);
			std::cout << "found: " << *it << std::endl;
		}
		catch (std::exception &e) { std::cout << "exception: " << e.what() << std::endl; }

		try
		{
			easyfind(d, 0);
			std::cout << "found: 0" << std::endl;
		}
		catch (std::exception &e) { std::cout << "0 not found: " << e.what() << std::endl; }
	}

	title("TESTING WITH CONST CONTAINER");
	{
		std::vector<int> v;
		v.push_back(7);
		v.push_back(14);
		v.push_back(21);
		const std::vector<int> cv(v);

		try
		{
			std::vector<int>::const_iterator it = easyfind(cv, 14);
			std::cout << "found: " << *it << std::endl;
		}
		catch (std::exception &e) { std::cout << "exception: " << e.what() << std::endl; }

		try
		{
			easyfind(cv, 99);
			std::cout << "found: 99" << std::endl;
		}
		catch (std::exception &e) { std::cout << "99 not found: " << e.what() << std::endl; }
	}

	title("TESTING FIRST OCCURRENCE ONLY");
	{
		std::vector<int> v;
		v.push_back(3);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);

		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "first occurrence of 5 at index " << (it - v.begin()) << std::endl;
	}

	return (0);
}
