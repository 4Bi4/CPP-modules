/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:28:32 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/22 21:15:36 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& copy);

	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			attack(const std::string& target);

	void			setName(const std::string& name);
	void			setHitPoints(unsigned int hitPoints);
	void			setEnergyPoints(unsigned int energyPoints);
	void			setAttackDamage(unsigned int attackDamage);

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
