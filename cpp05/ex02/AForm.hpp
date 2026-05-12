#pragma once

#include "Bureaucrat.hpp"

#define MIN_GRADE_TO_SIGN 150
#define MIN_GRADE_TO_EXECUTE 150

class AForm
{
public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExec);
	AForm(const AForm& copy);
	virtual ~AForm();

	AForm &operator=(const AForm& src);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(Bureaucrat const &executor) const;
	virtual void		executeAction() const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
