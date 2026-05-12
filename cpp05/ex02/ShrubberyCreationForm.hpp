#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

		std::string	_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		const std::string	&getTarget() const;
		void				executeAction() const;

};