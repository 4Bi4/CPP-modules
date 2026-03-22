/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:29:01 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/22 22:04:35 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	~FragTrap();
	FragTrap& operator=(const FragTrap& copy);

	void	highFivesGuys();
};

#endif
