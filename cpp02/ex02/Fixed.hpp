/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:38:37 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/09 19:36:59 by labia-fe         ###   ########.fr       */
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
	Fixed& operator=(const Fixed& copy);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_Value;
	static const int	_fractionalBits = 8;

	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
