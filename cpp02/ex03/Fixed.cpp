/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:48:32 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/14 19:02:35 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _Value(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& copy) : _Value(copy._Value) {}

Fixed::Fixed(int const value) : _Value(value << _fractionalBits) {}

Fixed::Fixed(float const value) : _Value(roundf(value * (1 << _fractionalBits))) {}

//	Assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_Value = other._Value;
	return (*this);
}

//	Comparison operators
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_Value > other._Value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_Value < other._Value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_Value >= other._Value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_Value <= other._Value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_Value == other._Value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_Value != other._Value);
}

//	Arithmetic operators
Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//	Increment/decrement operators
Fixed&	Fixed::operator++()
{
	this->_Value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_Value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_Value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_Value--;
	return (tmp);
}

//	Min/Max comparison methods
Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	const& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	const& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

//	Class methods
int Fixed::getRawBits(void) const
{
	return (this->_Value);
}

void Fixed::setRawBits(int const raw)
{
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

//	Stream insertion operator (printing rules)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
