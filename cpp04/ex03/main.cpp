/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:46:09 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 09:02:44 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n===== Basic Subject pouch =====" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* breixo = new Character("Breixo");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	breixo->equip(tmp);
	tmp = src->createMateria("cure");
	breixo->equip(tmp);

	ICharacter* martin = new Character("Martiño");

	breixo->use(0, *martin);
	breixo->use(1, *martin);

	std::cout << "\n===== Unknown Materia pouch =====" << std::endl;
	AMateria* ghost = src->createMateria("ghost");
	if (!ghost)
		std::cout << "createMateria(\"ghost\") returned NULL as expected" << std::endl;

	std::cout << "\n===== Invalid Index pouch =====" << std::endl;
	std::cout << "No output should appear between these two lines:" << std::endl;
	std::cout << "[start]" << std::endl;
	breixo->use(-1, *martin);
	breixo->use(42, *martin);
	std::cout << "[end]" << std::endl;

	std::cout << "\n===== Full Inventory Test =====" << std::endl;
	AMateria* ice1 = src->createMateria("ice");
	AMateria* ice2 = src->createMateria("ice");
	AMateria* cure1 = src->createMateria("cure");
	AMateria* cure2 = src->createMateria("cure");
	ICharacter* pouch = new Character("pouch");
	pouch->equip(ice1);
	pouch->equip(cure1);
	pouch->equip(ice2);
	pouch->equip(cure2);
	AMateria* extra = src->createMateria("ice");
	pouch->equip(extra);
	delete (extra);
	pouch->use(0, *martin);
	pouch->use(1, *martin);
	pouch->use(2, *martin);
	pouch->use(3, *martin);

	std::cout << "\n===== Unequip Test =====" << std::endl;
	pouch->unequip(1);
	std::cout << "No output should appear after this line:" << std::endl;
	pouch->use(1, *martin);
	delete (cure1);

	delete (martin);
	delete (breixo);
	delete (pouch);
	delete (src);
	return (0);
}

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }
