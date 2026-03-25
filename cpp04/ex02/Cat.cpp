/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:54:17 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 05:42:39 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	*this = copy;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = other._brain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "-> meow" << std::endl;
}

std::string	Cat::getIdea(unsigned int n)
{
	return (_brain->getIdea(n));
}

void	Cat::setIdea(const std::string& idea, unsigned int n)
{
	if (n >= 100 || idea == "")
		return ;
	_brain->setIdea(idea, n);
}

