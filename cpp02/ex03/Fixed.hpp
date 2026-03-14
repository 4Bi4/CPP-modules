/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:38:37 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/14 17:47:14 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed& copy);
	~Fixed();

	//	Assignment operator
	Fixed& operator=(const Fixed& other);

	//	Comparison operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	//	Arithmetic operators
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	//	Increment/decrement operators
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	//	Min/Max comparison methods
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(const Fixed &a, const Fixed &b);

	//	Class methods
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_Value;
	static const int	_fractionalBits = 8;

};

//	Stream insertion operator (printing rules)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
