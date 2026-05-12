#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("Presidential Pardon Form", 25, 5),
    _target("Unnamed Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
    AForm("Presidential Pardon Form", 25, 5),
    _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
    AForm(copy),
    _target(copy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
