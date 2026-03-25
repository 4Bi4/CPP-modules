/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:43:26 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:39:36 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other)
{
    AMateria::operator=(other);
    return (*this);
}

AMateria* Cure::clone() const
{
	AMateria* newCure = new Cure(*this);
	return (newCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
