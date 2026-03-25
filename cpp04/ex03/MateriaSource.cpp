/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:13:50 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 08:30:34 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; i++)
		_materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < MATERIA_SIZE; ++i)
		_materias[i] = other._materias[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIA_SIZE; ++i)
		delete (_materias[i]);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MATERIA_SIZE; ++i)
		{
			delete (_materias[i]);
			_materias[i] = other._materias[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MATERIA_SIZE; ++i)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MATERIA_SIZE; ++i)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (0);
}
