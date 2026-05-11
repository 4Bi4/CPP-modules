#include "Form.hpp"

Form::Form() :
	_name("Unnamed form"),
	_signed(false),
	_gradeToSign(MIN_GRADE_TO_SIGN),
	_gradeToExec(MIN_GRADE_TO_EXECUTE)
{
	std::cout << "Default constructor - [ Form ]" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	std::cout << "Parametric constructor - [ Form ]" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeToSign(copy._gradeToSign),
	_gradeToExec(copy._gradeToExec)
{
	std::cout << "Copy constructor - [ Form ]" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor - [ Form ]" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Assignment operator - [ Form ]" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.getSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExec();
	return (out);
}