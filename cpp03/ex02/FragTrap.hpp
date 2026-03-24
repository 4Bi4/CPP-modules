/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:29:01 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 22:07:39 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

# define FRAGTRAP_HP 100
# define FRAGTRAP_EP 100
# define FRAGTRAP_AD 30

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
