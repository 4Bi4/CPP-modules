/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:12:03 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 22:11:49 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	guille("Guille");
	DiamondTrap	jose("Jose");
	DiamondTrap	copy(guille);
	DiamondTrap	assigned(jose);

	assigned = guille;
	std::cout << std::endl;

	guille.whoAmI();
	jose.whoAmI();
	guille.highFivesGuys();
	jose.guardGate();

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nRound " << i + 1 << std::endl;
		guille.attack(jose.getName());
		jose.takeDamage(guille.getAttackDamage());
		std::cout << jose.getName() << " has " << jose.getHitPoints() << " hp left." << std::endl;
	}

	std::cout << "\nTrying to repair jose:" << std::endl;
	jose.beRepaired(10);

	std::cout << "\nSpending all energy:" << std::endl;
	for (int i = 0; i < 53; i++)
		guille.attack("training dummy");

	std::cout << "\nAfter energy is gone:" << std::endl;
	guille.beRepaired(5);
	guille.guardGate();
	guille.whoAmI();

	std::cout << "\nDestroying one and checking inherited actions on a dead DiamondTrap:" << std::endl;
	assigned.takeDamage(200);
	assigned.highFivesGuys();
	assigned.guardGate();
	assigned.whoAmI();

	std::cout << std::endl;
	return (0);
}
