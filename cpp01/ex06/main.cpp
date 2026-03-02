/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:41:18 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/02 19:47:46 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <level>" << std::endl, 1);
	
	Harl harl;
	harl.filterComplain(argv[1]);
	return (0);
}
