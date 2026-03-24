/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:41:36 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 22:07:17 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("???"), _hitPoints(CLAPTRAP_HP), _energyPoints(CLAPTRAP_EP), _attackDamage(CLAPTRAP_AD)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(CLAPTRAP_HP), _energyPoints(CLAPTRAP_EP), _attackDamage(CLAPTRAP_AD)
{
	std::cout << "ClapTrap " << this->_name << " created with name constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " created with copy constructor." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called." << std::endl;
	return (*this);
}

void	ClapTrap::setName(const std::string& name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hp)
{
	this->_hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(unsigned int energy)
{
	this->_energyPoints = energy;
}

void	ClapTrap::setAttackDamage(unsigned int damage)
{
	this->_attackDamage = damage;
}
std::string	ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << this->_name << " can't attack, he has no energy left! ❌" << std::endl;
		return;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << this->_name << " can't attack, he's dead! ❌" << std::endl;
		return;
	}
		std::cout << this->_name << " attacks " << target << " for " << this->_attackDamage << " points of damage! ⚔️" << std::endl;
		this->_energyPoints--;
		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "Leave " << this->_name << " alone, he's already dead! ❌" << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << this->_name << " got hit by " << amount << " points of damage! 🗡️" << std::endl;
	if (this->_hitPoints < 1)
		std::cout << this->_name << " fainted! 💀" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << this->_name << " can't be repaired, he has no energy left! ❌" << std::endl;
		return;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << this->_name << " can't be repaired, he's dead! ❌" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_name << " got repaired by " << amount << " points of health! 💚" << std::endl;
}
