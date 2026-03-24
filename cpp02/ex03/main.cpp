/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:38:45 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/24 19:10:05 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(int ac, char *av[])
{
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);
	bool result;

	if (ac < 3)
	{
		std::cout << "Executing default values:\n" << "\na(0,0) b(1,0) c(0,1)\npoint(0.5,0.5)\n" << std::endl;
		Point point(0.3, 0.3);
		result = bsp(a, b, c, point);
	}
	else
	{
		//	not parsing input
		float x = atof(av[1]);
		float y = atof(av[2]);
		Point point(x, y);
		std::cout << "Executing with custom values:\n" << std::endl;
		std::cout << "a(0,0) b(1,0) c(0,1)\npoint: ("  << point.getX() << ", " << point.getY() << ")\n" << std::endl;
		result = bsp(a, b, c, point);
	}
	std::cout << "Point is " << (result ? "✅ inside" : "❌ outside") << " the triangle." << std::endl;
	
	return (0);
}
