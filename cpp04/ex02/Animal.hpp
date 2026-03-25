/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:38:48 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 05:52:12 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal& copy);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

	std::string getType() const;

	virtual void	makeSound() const = 0;

protected:
	std::string _type;
};

#endif
