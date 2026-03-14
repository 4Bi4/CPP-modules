/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:50:28 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/14 18:58:14 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
		new (this) Point(other._x.toFloat(), other._y.toFloat());
	return (*this);
}

//	const variables cannot be changed.
// Point&	Point::operator=(const Point& other)
// {
// 	void(*other);
// 	return (*this);
// }

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
