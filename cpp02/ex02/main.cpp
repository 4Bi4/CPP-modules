/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:38:45 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 19:08:38 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "\na: " << a << "\nb: " << b << std::endl;

	std::cout << "\n=== ++a OPERATOR ===" << std::endl;
	std::cout << "a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\n=== a++ OPERATOR ===" << std::endl;
	std::cout << "a: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\n=== --a OPERATOR ===" << std::endl;
	std::cout << "a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\n=== a-- OPERATOR ===" << std::endl;
	std::cout << "a: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\n=== BOOLEANS ===" << std::endl;
	std::cout << "a: " << a << "  b: " << b << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl;

	std::cout << "\n=== ARITHMETIC OPERATORS ===" << std::endl;
	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "a - b is " << (a - b) << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;

	std::cout << "\n=== MAX&MIN ===" << std::endl;
	std::cout << "max between a(" << a << ") and b(" << b << ") is " << Fixed::max(a, b) << std::endl;
	std::cout << "min between a(" << a << ") and b(" << b << ") is " << Fixed::min(a, b) << "\n" << std::endl;
	return (0);
}
