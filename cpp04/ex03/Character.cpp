/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:08:02 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:32:15 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("")
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		delete _inventory[i];
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < INVENTORY_SIZE; ++i)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE)
		_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && _inventory[idx])
		_inventory[idx]->use(target);
}