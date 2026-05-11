#pragma once

#include "Bureaucrat.hpp"

#define MIN_GRADE_TO_SIGN 150
#define MIN_GRADE_TO_EXECUTE 150

class Form
{
public:

	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExec);
	Form(const Form &copy);
	~Form();

	Form &operator=(const Form &src);

	const std::string	&getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	void				beSigned(const Bureaucrat &bureaucrat);

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

private:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const Form &form);
