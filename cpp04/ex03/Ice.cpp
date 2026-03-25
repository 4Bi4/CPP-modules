/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:47:29 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:39:34 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* newIce = new Ice(*this);
	return (newIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
