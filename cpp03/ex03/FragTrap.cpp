/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:28:53 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 21:58:22 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setName("Default FragTrap");
	this->setHitPoints(FRAGTRAP_HP);
	this->setEnergyPoints(FRAGTRAP_EP);
	this->setAttackDamage(FRAGTRAP_AD);
	std::cout << "FragTrap from ClapTrap created with default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(FRAGTRAP_HP);
	this->setEnergyPoints(FRAGTRAP_EP);
	this->setAttackDamage(FRAGTRAP_AD);
	std::cout << "FragTrap from ClapTrap created with name: " << this->getName() << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap from ClapTrap copied." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "FragTrap assignment operator called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->getHitPoints() < 1)
		std::cout << this->getName() << " cannot high five right now. ❌" << std::endl;
	else
		std::cout << "FragTrap " << this->getName() << " is requesting a high five! 🙌" << std::endl;
}
