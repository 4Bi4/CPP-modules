#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    const std::string &getTarget() const;

    virtual void executeAction() const;

private:
    std::string _target;
};
