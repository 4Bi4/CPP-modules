/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:48:23 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 03:17:07 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& copy);
	~Cat();
	Cat& operator=(const Cat& other);

	void		makeSound() const;
	std::string	getIdea(unsigned int n);
	void		setIdea(const std::string &idea, unsigned int n);
	
private:
	Brain*	_brain;
};

#endif