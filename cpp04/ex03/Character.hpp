/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:07:00 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:32:12 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character& other);
	~Character();
	Character& operator=(const Character& other);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[INVENTORY_SIZE];
};
