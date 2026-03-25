/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:31:35 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:23:54 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(const AMateria& other);
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& other);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string _type;
};
