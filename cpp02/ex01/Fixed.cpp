/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:48:32 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/11 20:24:13 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _Value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _Value(copy._Value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _Value(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _Value(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
		this->_Value = copy._Value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_Value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_Value = raw;
}

int Fixed::toInt(void) const
{
	return (this->_Value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_Value / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}