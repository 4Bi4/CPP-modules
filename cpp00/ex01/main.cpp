/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:35:06 by labia-fe          #+#    #+#             */
/*   Updated: 2026/02/23 20:28:12 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	line;

	std::cout << "Starting PhoneBook app...\n" << std::endl;
	std::cout << "Welcome to your PhoneBook!!! ^^\n" << std::endl;
	std::cout << "Commands:\n- ADD (creates a new contact)\n- SEARCH (looks for a specific contact)\n- EXIT (closes the program)\n" << std::endl;

	while (1)
	{
		std::cout << "-> ";
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout << "\n👋" << std::endl;
			break ;
		}
		if (line.empty() || (line.find_first_not_of(' ') == std::string::npos))
		{
			std::cout << "Write \"ADD\", \"SEARCH\" or \"EXIT\"" << std::endl;
			continue ;
		}
		if (line == "add" || line == "ADD")
			phoneBook.addContact();
		else if (line == "search" || line == "SEARCH")
			phoneBook.searchContact();
		else if (line == "exit" || line == "EXIT")
		{
			std::cout << "\n👋" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Unknown command \"" << line << "\", please try again\n" << std::endl;
			std::cout << "Commands:\n- ADD (creates a new contact)\n- SEARCH (looks for a specific contact)\n- EXIT (closes the program)\n" << std::endl;
		}
	}
	return (0);
}
