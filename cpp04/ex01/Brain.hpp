/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:29:27 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 03:17:00 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& copy);
	~Brain();
	Brain& operator=(const Brain& other);

	std::string	getIdea(unsigned int n);
	void		setIdea(const std::string &idea, unsigned int i);

private:
	std::string	_ideas[100];
};
