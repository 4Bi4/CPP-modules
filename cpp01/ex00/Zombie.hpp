/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:08:34 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:29:09 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	setName(std::string name);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
