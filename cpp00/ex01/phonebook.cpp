/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:13:12 by labia-fe          #+#    #+#             */
/*   Updated: 2026/02/23 20:17:50 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->current = 0;
	this->amount = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	name, number;

	while (1)
	{
		std::cout << "Enter name: ";
		if (!std::getline(std::cin, name))
		{
			std::cout << std::endl;
			return ;
		}
		else if (name.empty() || (name.find_first_not_of(' ') == std::string::npos))
			std::cout << "Name cannot be empty :(, try again" << std::endl;
		else
			break ;
	}
	contacts[current].setName(name);

	while (1)
	{
		std::cout << "Enter number: ";
		if (!std::getline(std::cin, number))
		{
			std::cout << std::endl;
			return ;
		}
		else if (number.empty() || (number.find_first_not_of(' ') == std::string::npos))
			std::cout << "Number cannot be empty >:(, try again" << std::endl;
		else
			break ;
	}
	contacts[current].setNumber(number);

	current++;
	if (amount < 8)
		amount++;
	if (current > 7)
		current = 0;
}

std::string	formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	else
		return (std::string(10 - str.length(), ' ') + str);
}

void	PhoneBook::searchContact()
{
	int i = 0;

	if (amount == 0)
	{
		std::cout << "No contact data." << std::endl;
		return ;
	}
	std::cout << "_|__________" << std::endl;
	while (i < amount)
	{
		std::cout << (i + 1) << "|" << formatField(contacts[i].getName()) << std::endl;
		i++;
	}
	std::cout << "Select a contact > ";
	std::string line;
	if (!std::getline(std::cin, line))
	{
		std::cout << std::endl;
		return ;
	}
	i = std::atoi(line.c_str());
	if (i > 0)
	{
		if (i <= amount)
		{
			i--;
			std::cout << std::endl;
			std::cout << "Name: " << contacts[i].getName() << std::endl;
			std::cout << "Number: " << contacts[i].getNumber() << std::endl;
			std::cout << std::endl;
		}
		else
			std::cout << "Contact not found :(" << std::endl;
	}
	else
		std::cout << "Invalid contact number" << std::endl;
}
