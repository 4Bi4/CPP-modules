/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:21:00 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:25:16 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int	main(void)
{
	std::string init = "HI THIS IS BRAIN";
	std::string* stringPTR = &init;
	std::string& stringREF = init;

	std::cout << "Memory address of the string variable: " << &init << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of the string variable: " << init << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;
	return (0);
}