/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:18:26 by labia-fe          #+#    #+#             */
/*   Updated: 2026/02/17 23:18:31 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string strCapitalizer(std::string str){
	for (int i = 0; str[i]; i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	return (str);
}

int	main(int ac, char **av){
	if (ac > 1)
	{
		for (int i = 1; av[i]; i++)
			std::cout << strCapitalizer(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}
