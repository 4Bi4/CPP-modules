/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:58:05 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 22:08:02 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_HP 100
# define SCAVTRAP_EP 50
# define SCAVTRAP_AD 20

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& copy);

	void	guardGate();
	void	attack(const std::string& target);
};

#endif
