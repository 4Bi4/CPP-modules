#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	//	Init RNG
	std::srand(std::time(NULL));

	std::cout << "\n=== Testing Intern Class ===" << std::endl;

	Intern someRandomIntern;
	AForm *form;

	std::cout << "\n--- Test 1: Create robotomy request form ---" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\n--- Test 2: Create shrubbery creation form ---" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\n--- Test 3: Create presidential pardon form ---" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Marvin");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\n--- Test 4: Create invalid form ---" << std::endl;
	form = someRandomIntern.makeForm("coffee request", "Bob");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	else
		std::cout << "Form pointer is NULL" << std::endl;

	std::cout << "\n=== Testing Intern with Bureaucrat ===" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm *rrf = intern.makeForm("robotomy request", "Bender");

		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}
