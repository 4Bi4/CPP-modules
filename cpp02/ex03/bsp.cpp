/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:28:19 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/14 18:56:22 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	Some black magic math to calculate the cross product of vectors AB and AC
double	crossProduct(Point const a, Point const b, Point const c)
{
	double	crossA = (b.getX() - a.getX()).toFloat() * (c.getY() - a.getY()).toFloat();
	double	crossB = (b.getY() - a.getY()).toFloat() * (c.getX() - a.getX()).toFloat();
	return (crossA - crossB);
}

//	Returns true if point is inside the triangle formed by a, b and c
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	double	abp = crossProduct(a, b, point);
	double	bcp = crossProduct(b, c, point);
	double	cap = crossProduct(c, a, point);

	//	Same sign = inside the triangle
	if ((abp > 0 && bcp > 0 && cap > 0) || (abp < 0 && bcp < 0 && cap < 0))
		return (true);
	return (false);
}
