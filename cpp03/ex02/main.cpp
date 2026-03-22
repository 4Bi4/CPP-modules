/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:12:03 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/22 20:25:06 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	alpha("Alpha");
	FragTrap	beta("Beta");
	FragTrap	copy(alpha);
	FragTrap	assigned;

	assigned = beta;
	std::cout << std::endl;

	alpha.highFivesGuys();

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nRound " << i + 1 << std::endl;
		alpha.attack(beta.getName());
		beta.takeDamage(alpha.getAttackDamage());
		std::cout << beta.getName() << " has " << beta.getHitPoints() << " hp left." << std::endl;
	}

	std::cout << "\nTrying to repair Beta:" << std::endl;
	beta.beRepaired(10);

	std::cout << "\nSpending all energy:" << std::endl;
	copy.setName("Alpha Copy");
	for (int i = 0; i < 103; i++)
		copy.attack("training dummy");

	std::cout << "\nAfter energy is gone:" << std::endl;
	copy.beRepaired(5);
	copy.highFivesGuys();

	std::cout << "\nDestroying one and checking high fives on a dead FragTrap:" << std::endl;
	assigned.takeDamage(200);
	assigned.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
