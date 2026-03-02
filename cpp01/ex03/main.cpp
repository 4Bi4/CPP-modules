/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:35:34 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:59:05 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	// Create the weapons
	Weapon	sword = Weapon("Master Sword");
	Weapon	stick = Weapon("Tree branch");

	Weapon	club = Weapon("Boko club");
	Weapon	bow = Weapon("Tulin's bow");
	Weapon	shield = Weapon("Hylian shield");

	// Summon some humans
	HumanA	Hudson = HumanA("Hudson", stick);
	HumanA	Link = HumanA("Link", sword);
	
	HumanB	Terry = HumanB("Terry");
	Terry.setWeapon(club);
	HumanB	Tulin = HumanB("Tulin");
	Tulin.setWeapon(bow);

	// Try to attack
	Hudson.attack();
	Link.attack();
	Terry.attack();
	Tulin.attack();

	// Change weapons (limit testing)
	Terry.setWeapon(shield);
	Terry.attack();

	return (0);
}
