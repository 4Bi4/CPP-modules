/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:12:03 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/22 19:19:33 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	guardian("Guardian");
	ScavTrap	intruder("Intruder");
	ScavTrap	backup(guardian);
	ScavTrap	copy;

	copy = intruder;
	std::cout << std::endl;

	guardian.guardGate();
	guardian.setAttackDamage(20);

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nRound " << i + 1 << std::endl;
		guardian.attack(intruder.getName());
		intruder.takeDamage(guardian.getAttackDamage());
		std::cout << intruder.getName() << " has " << intruder.getHitPoints() << " hp left." << std::endl;
	}

	std::cout << "\nTrying to repair Intruder:" << std::endl;
	intruder.beRepaired(10);

	std::cout << "\nSpending all energy:" << std::endl;
	backup.setName("Guardian 2");
	for (int i = 0; i < 53; i++)
		backup.attack("training dummy");

	std::cout << "\nAfter energy is gone:" << std::endl;
	backup.beRepaired(5);
	backup.guardGate();

	std::cout << "\nDestroying one and checking guardGate on a dead ScavTrap:" << std::endl;
	copy.takeDamage(200);
	copy.guardGate();

	std::cout << std::endl;
	return (0);
}
