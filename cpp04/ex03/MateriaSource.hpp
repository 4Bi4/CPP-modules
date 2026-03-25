/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:11:44 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:12:51 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource();
	MateriaSource& operator=(const MateriaSource& other);
	
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(const std::string& type);

private:
	AMateria*	_materias[MATERIA_SIZE];
};
