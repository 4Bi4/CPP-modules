/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:02:45 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 05:00:11 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& copy);
	~Dog();
	Dog& operator=(const Dog& copy);

	void		makeSound() const;
	std::string	getIdea(unsigned int n);
	void		setIdea(const std::string &idea, unsigned int n);

private:
	Brain*	_brain;
};

#endif