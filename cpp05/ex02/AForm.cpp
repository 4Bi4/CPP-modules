#include "AForm.hpp"

AForm::AForm() :
	_name("Unnamed Aform"),
	_signed(false),
	_gradeToSign(MIN_GRADE_TO_SIGN),
	_gradeToExec(MIN_GRADE_TO_EXECUTE) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeToSign(copy._gradeToSign),
	_gradeToExec(copy._gradeToExec) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm& src)
{
	if (this == &src)
		return (*this);
	this->_signed = src._signed;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw GradeTooLowException();
	this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.getSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExec();
	return (out);
}