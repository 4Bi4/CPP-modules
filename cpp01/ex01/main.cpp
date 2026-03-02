/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:32:51 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:18:21 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\n[🧟 ROUND 1 🧟]\n" << std::endl;
	Zombie* horde = zombieHorde(4, "Fernando");
	delete[] (horde);

	std::cout << "\n[🧟 ROUND 2 🧟]\n" << std::endl;
	horde = zombieHorde(7, "Alexia");
	delete[] (horde);

	std::cout << "\n[🧟 ROUND 3 🧟]\n" << std::endl;
	horde = zombieHorde(13, "Humberto");
	delete[] (horde);
	return (0);
}