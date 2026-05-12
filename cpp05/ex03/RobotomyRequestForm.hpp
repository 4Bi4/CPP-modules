#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    const std::string &getTarget() const;

    virtual void executeAction() const;

private:
    std::string _target;
};
