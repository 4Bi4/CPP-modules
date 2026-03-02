/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:33:24 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:12:41 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 0)
		return (NULL);
	
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream temp;
		temp << name << "_" << (i + 1);
		horde[i].setName(temp.str());
		horde[i].announce();
	}
	return(horde);
}
