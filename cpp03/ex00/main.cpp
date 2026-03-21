/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:12:03 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/21 18:50:31 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap unnamed;
	ClapTrap carlos(unnamed);
	ClapTrap pepe;

	carlos.setName("Carlos");
	pepe.setName("Pepe");

	for (int i = 0; i < 12; i++)
	{
		std::cout << "\nRound " << i + 1 << std::endl;
		carlos.attack("Pepe");
		pepe.takeDamage(carlos.getAttackDamage());
	}
	std::cout << std::endl;

	carlos.beRepaired(5);
	pepe.beRepaired(5);
	std::cout << std::endl;
	return (0);
}
