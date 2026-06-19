#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n---- Testing promotion and demotion ----" << std::endl;

	std::cout << "\nCreating Bureaucrat with grade 1 (highest):" << std::endl;
	try
	{
		Bureaucrat	b1("Alice", 1);
		std::cout << b1 << std::endl;
		b1.promote();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	//	The error message comes up after the Bureaucrat destructor message
	//	because the rey module is destroyed before the catch module
	//	is executed, so the exception is thrown after the destructor is called.

	std::cout << "\nCreating Bureaucrat with grade 150 (lowest):" << std::endl;
	try
	{
		Bureaucrat	b2("Bob", 150);
		std::cout << b2 << std::endl;
		b2.demote();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n---- Testing edge cases ----" << std::endl;

	std::cout << "\nCreating Bureaucrat with grade 0 (too high):" << std::endl;
	try
	{
		Bureaucrat	b0("Invalid", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nCreating Bureaucrat with grade 151 (too low):" << std::endl;
	try
	{
		Bureaucrat	b3("Invalid", 151);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nCreating Bureaucrat with grade -20000 (imposible):" << std::endl;
	try
	{
		Bureaucrat	b4("Imposible", -20000);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Test finished succesfully ===" << std::endl;
	return (0);
}