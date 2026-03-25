/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:03:43 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 05:42:34 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "-> woof" << std::endl;
}

std::string	Dog::getIdea(unsigned int n)
{
	return (_brain->getIdea(n));
}

void	Dog::setIdea(const std::string& idea, unsigned int n)
{
	if (n >= 100 || idea == "")
		return ;
	_brain->setIdea(idea, n);
}
