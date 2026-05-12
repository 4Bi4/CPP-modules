#pragma once

#include <iostream>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat();

    Bureaucrat&        operator=(const Bureaucrat& other);

    const std::string&    getName() const;
    int                    getGrade() const;

    void    promote();
    void    demote();
    void    signForm(class AForm &form);
    void    executeForm(class AForm const &form) const;

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

protected:
    const std::string    _name;
    int                    _grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
