/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:41:36 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/21 18:49:37 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("???"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
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
		std::cout << "ClapTrap " << this->_name << " can't attack, he has no energy left! ❌" << std::endl;
		return;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack, he's dead! ❌" << std::endl;
		return;
	}
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " for " << this->_attackDamage << " points of damage! ⚔️" << std::endl;
		this->_energyPoints--;
		
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "Leave " << this->_name << " alone, he's already dead! ❌" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " got hit by " << amount << " points of damage! 🗡️" << std::endl;
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " fainted! 💀" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired, he has no energy left! ❌" << std::endl;
		return;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired, he's dead! ❌" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " got repaired by " << amount << " points of health! 🛡️" << std::endl;
}
