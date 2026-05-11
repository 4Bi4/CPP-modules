#include "Form.hpp"

Bureaucrat::Bureaucrat() :
	_name("Unidentified bureaucrat"),
	_grade(150)
{
	std::cout << "Default constructor - [ Bureaucrat ]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name),
	_grade(grade)
{
	std::cout << "Parametric constructor - [ Bureaucrat ]" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	_name(copy._name),
	_grade(copy._grade)
{
	std::cout << "Copy constructor - [ Bureaucrat ]" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor - [ Bureaucrat ]" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Assignment operator - [ Bureaucrat ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(class Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::promote()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::demote()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("-> [ERROR] Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("-> [ERROR] Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
