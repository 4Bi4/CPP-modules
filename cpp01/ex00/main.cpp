/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:11:58 by labia-fe          #+#    #+#             */
/*   Updated: 2026/02/28 20:47:58 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* heapZombie = newZombie("Geroge Heap");

    heapZombie->announce();
    randomChump("Daniel Stack");
    delete (heapZombie);
    return (0);
}
