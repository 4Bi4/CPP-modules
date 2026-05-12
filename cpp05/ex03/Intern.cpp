#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

typedef AForm* (*form_creator)(const std::string&);

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    form_creator creators[3] = {&createShrubbery, &createRobotomy, &createPresidential};

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            AForm* form = creators[i](target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cout << "Intern couldn't create " << formName << std::endl;
    return NULL;
}
