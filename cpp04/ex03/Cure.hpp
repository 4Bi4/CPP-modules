/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:53:59 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:38:24 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	virtual ~Cure();
	Cure& operator=(const Cure& other);

	void use(ICharacter& target);
	AMateria* clone() const;
};