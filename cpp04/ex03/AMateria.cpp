/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:43:24 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:36:49 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
