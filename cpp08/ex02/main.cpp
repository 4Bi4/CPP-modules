#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

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
	title("SUBJECT EXAMPLE");
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it  = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		it++;
		it--;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}

		std::stack<int> s(mstack);
		(void)s;
	}

	title("SAME TEST WITH std::list (output must match)");
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it  = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		it++;
		it--;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}

	title("TESTING CONST ITERATOR");
	{
		MutantStack<int> ms;
		ms.push(10);
		ms.push(20);
		ms.push(30);

		const MutantStack<int> cms(ms);
		MutantStack<int>::const_iterator it  = cms.begin();
		MutantStack<int>::const_iterator ite = cms.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}

	title("TESTING REVERSE ITERATOR");
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);
		ms.push(4);
		ms.push(5);

		std::cout << "forward:  ";
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "reverse:  ";
		for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	title("TESTING COPY CONSTRUCTOR AND ASSIGNMENT");
	{
		MutantStack<int> a;
		a.push(100);
		a.push(200);
		a.push(300);

		MutantStack<int> b(a);
		b.push(400);

		std::cout << "a -> (3 elements): ";
		for (MutantStack<int>::iterator it = a.begin(); it != a.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "b -> (a + 400):    ";
		for (MutantStack<int>::iterator it = b.begin(); it != b.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		MutantStack<int> c;
		c = a;
		c.push(999);
		std::cout << "c -> (a + 900):    ";
		for (MutantStack<int>::iterator it = c.begin(); it != c.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	title("TESTING WITH STRING TYPE");
	{
		MutantStack<std::string> ms;
		ms.push("hello");
		ms.push("world");
		ms.push("!");

		for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); it++)
			std::cout << *it << std::endl;
	}

	return (0);
}
