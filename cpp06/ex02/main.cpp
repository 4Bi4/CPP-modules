#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//	Generate a random instance of A, B, or C
Base *generate(void)
{
	int r = rand() % 3;
	if (r == 0) return (new A());
	if (r == 1) return (new B());
	return (new C());
}

//	Identify the type of the object pointed to by p
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

//	Identify the type of the object referenced by p
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &) {}
	
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &) {}
}

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
	srand(static_cast<unsigned int>(time(NULL)));

	title("TESTING EXPLICIT TYPES");
	{
		A a;
		B b;
		C c;

		std::cout << "--- A ---" << std::endl;
		std::cout << "identify(ptr): "; identify(&a);
		std::cout << "identify(ref): "; identify(a);
		std::cout << std::endl;

		std::cout << "--- B ---" << std::endl;
		std::cout << "identify(ptr): "; identify(&b);
		std::cout << "identify(ref): "; identify(b);
		std::cout << std::endl;

		std::cout << "--- C ---" << std::endl;
		std::cout << "identify(ptr): "; identify(&c);
		std::cout << "identify(ref): "; identify(c);
		std::cout << std::endl;
	}

	title("TESTING RANDOM GENERATION");
	for (int i = 0; i < 6; ++i)
	{
		Base *obj = generate();
		std::cout << "identify(ptr): "; identify(obj);
		std::cout << "identify(ref): "; identify(*obj);
		std::cout << std::endl;
		delete obj;
	}

	return (0);
}
