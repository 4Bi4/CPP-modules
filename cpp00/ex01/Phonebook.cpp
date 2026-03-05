/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:13:12 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/05 18:20:08 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->current = 0;
	this->amount = 0;
}

PhoneBook::~PhoneBook() {}


//	Helper function, prompts the user for a field and validates the input
//  RETURN: the input std::string, or empty string if EOF is reached
std::string promptField(std::string fieldName)
{
    std::string input = "";
	
    while (1)
    {
        std::cout << "Enter " << fieldName << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            return ("");
        }
        else if (input.empty() || (input.find_first_not_of(' ') == std::string::npos))
            std::cout << fieldName << " cannot be empty :(, try again" << std::endl;
        else
            break ;
    }
    return (input);
}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	firstName = promptField("first name");
	lastName = promptField("last name");
	nickname = promptField("nickname");
	phoneNumber = promptField("phone number");
	darkestSecret = promptField("darkest secret");

	contacts[current].setFirstName(firstName);
	contacts[current].setLastName(lastName);
	contacts[current].setNickname(nickname);
	contacts[current].setPhoneNumber(phoneNumber);
	contacts[current].setDarkestSecret(darkestSecret);

	current++;
	if (amount < 8)
		amount++;
	if (current > 7)
		current = 0;
}

//	Helper function for search contact, formats a field to fit in 10 characters
//	RETURN: the formatted field
std::string	formatField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	else
		return (std::string(10 - field.length(), ' ') + field);
}

void	PhoneBook::searchContact()
{
	int i = 0;

	if (amount == 0)
	{
		std::cout << "No contact data." << std::endl;
		return ;
	}
	std::cout << "0|First Name| Last Name|  Nickname" << std::endl;
	std::cout << "_|________________________________" << std::endl;
	while (i < amount)
	{
		std::cout << (i + 1) << "|" << formatField(contacts[i].getFirstName())
		<< "|" << formatField(contacts[i].getLastName())
		<< "|" << formatField(contacts[i].getNickname()) << std::endl;
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
			std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
			std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
			std::cout << std::endl;
		}
		else
			std::cout << "Contact not found :(" << std::endl;
	}
	else
		std::cout << "Invalid contact number" << std::endl;
}
