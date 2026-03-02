/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:47:36 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/02 19:29:43 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <level>" << std::endl, 1);
	
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
