/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:05:22 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 21:58:20 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setName("Default ScavTrap");
	this->setHitPoints(SCAVTRAP_HP);
	this->setEnergyPoints(SCAVTRAP_EP);
	this->setAttackDamage(SCAVTRAP_AD);
	std::cout << "ScavTrap from ClapTrap created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(SCAVTRAP_HP);
	this->setEnergyPoints(SCAVTRAP_EP);
	this->setAttackDamage(SCAVTRAP_AD);
	std::cout << "ScavTrap from ClapTrap created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap from ClapTrap copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " can't attack, he has no energy left! ❌" << std::endl;
		return;
	}
	if (this->getHitPoints() < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " can't attack, he's dead! ❌" << std::endl;
		return;
	}
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << " for " << this->getAttackDamage() << " points of damage! ⚔️" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);	
}

void	ScavTrap::guardGate()
{
	if (this->getHitPoints() < 1)
		std::cout << this->getName() << " cannot switch to gate-keeper mode, let him rest in peace. ❌" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " is now in gate-keeper mode. 🛡️" << std::endl;
}
