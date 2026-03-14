/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:44:59 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/14 18:08:05 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& copy);
	~Point();

	Point&	operator=(const Point& other);

	Fixed	getX() const;
	Fixed	getY() const;

private:
	Fixed const _x;
	Fixed const _y;
};

#endif