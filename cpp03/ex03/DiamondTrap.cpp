/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:42:33 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 21:06:30 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap("Default"), ScavTrap("Default"), _name("Default")
{
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "HP " << this->getHitPoints();
	std::cout << " EP " << this->getEnergyPoints();
	std::cout << " AD " << this->getAttackDamage() << " ";
	std::cout << "DiamondTrap name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		this->_name = copy._name;
	}
	std::cout << "DiamondTrap assignment operator called." << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}
