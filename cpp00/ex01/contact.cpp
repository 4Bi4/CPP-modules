/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:53:46 by labia-fe          #+#    #+#             */
/*   Updated: 2026/02/18 15:10:55 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::setName(const std::string &name)
{
	this->name = name;
}

void	Contact::setNumber(const std::string &number)
{
	this->number = number;
}

std::string	Contact::getName() const
{
	return (this->name);
}

std::string	Contact::getNumber() const
{
	return (this->number);
}
