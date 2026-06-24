#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

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
	title("SUBJECT EXAMPLE (shortestSpan=2, longestSpan=14)");
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan()  << std::endl;
	}

	title("TESTING EXCEPTION: SPAN FULL");
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try { sp.addNumber(4); }
		catch (std::exception &e) { std::cout << "caught: " << e.what() << std::endl; }
	}

	title("TESTING EXCEPTION: NO SPAN (0 elements)");
	{
		Span sp(5);
		try { sp.shortestSpan(); }
		catch (std::exception &e) { std::cout << "shortestSpan: " << e.what() << std::endl; }
		try { sp.longestSpan(); }
		catch (std::exception &e) { std::cout << "longestSpan:  " << e.what() << std::endl; }
	}

	title("TESTING EXCEPTION: NO SPAN (1 element)");
	{
		Span sp(5);
		sp.addNumber(42);
		try { sp.shortestSpan(); }
		catch (std::exception &e) { std::cout << "shortestSpan: " << e.what() << std::endl; }
		try { sp.longestSpan(); }
		catch (std::exception &e) { std::cout << "longestSpan:  " << e.what() << std::endl; }
	}

	title("TESTING WITH DUPLICATES (shortestSpan should be 0)");
	{
		Span sp(4);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(10);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
	}

	title("TESTING addNumbers WITH ITERATOR RANGE (vector)");
	{
		std::vector<int> v;
		v.push_back(100);
		v.push_back(200);
		v.push_back(300);
		v.push_back(400);
		v.push_back(500);

		Span sp(5);
		sp.addNumbers(v.begin(), v.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
	}

	title("TESTING addNumbers WITH ITERATOR RANGE (list)");
	{
		std::list<int> l;
		l.push_back(10);
		l.push_back(1);
		l.push_back(50);
		l.push_back(3);

		Span sp(4);
		sp.addNumbers(l.begin(), l.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
	}

	title("TESTING addNumbers OVERFLOW (range too large)");
	{
		std::vector<int> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(i);

		Span sp(3);
		try { sp.addNumbers(v.begin(), v.end()); }
		catch (std::exception &e) { std::cout << "caught: " << e.what() << std::endl; }
	}

	title("TESTING WITH 10,000 RANDOM NUMBERS");
	{
		srand(static_cast<unsigned int>(time(NULL)));

		Span sp(10000);
		std::vector<int> v;
		for (int i = 0; i < 10000; ++i)
			v.push_back(rand());
		sp.addNumbers(v.begin(), v.end());

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl;
	}

	title("TESTING COPY CONSTRUCTOR AND ASSIGNMENT");
	{
		Span a(3);
		a.addNumber(1);
		a.addNumber(2);
		a.addNumber(3);

		Span b(a);
		std::cout << "copy - shortestSpan: " << b.shortestSpan() << std::endl;
		std::cout << "copy - longestSpan:  " << b.longestSpan()  << std::endl;

		Span c(1);
		c = a;
		std::cout << "assign - shortestSpan: " << c.shortestSpan() << std::endl;
		std::cout << "assign - longestSpan:  " << c.longestSpan()  << std::endl;
	}

	return (0);
}
