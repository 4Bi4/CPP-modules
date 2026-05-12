
//	Form already includes Bureaucrat
#include "Form.hpp"

int main(void)
{
	std::cout << "\n=== Testing Form Class ===" << std::endl;

	try
	{
		std::cout << "\n--- Test 1: Create valid form ---" << std::endl;
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 2: Form with grade too high (0) ---" << std::endl;
		Form form2("Invalid Form", 0, 25);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 3: Form with grade too low (151) ---" << std::endl;
		Form form3("Invalid Form", 50, 151);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing signForm ===" << std::endl;

	try
	{
		std::cout << "\n--- Test 4: Bureaucrat signs form successfully ---" << std::endl;
		Bureaucrat bob("Bob", 40);
		Form taxForm("Tax Form", 50, 25);
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 5: Bureaucrat fails to sign form ---" << std::endl;
		Bureaucrat lowBob("LowBob", 100);
		Form secretForm("Secret Form", 50, 25);
		std::cout << lowBob << std::endl;
		std::cout << secretForm << std::endl;
		lowBob.signForm(secretForm);
		std::cout << secretForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 6: Form beSigned throws exception ---" << std::endl;
		Bureaucrat intern("Intern", 150);
		Form topSecret("Top Secret", 1, 1);
		std::cout << intern << std::endl;
		std::cout << topSecret << std::endl;
		topSecret.beSigned(intern);
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test finished succesfully ===" << std::endl;
	return (0);
}