/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:30:31 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 06:24:54 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

#define ARRAY 4

int	main()
{
	//	Creating Animal array
	Animal** pets = new Animal*[ARRAY];

	//	Assigning odd numbers to dogs and even to cats and introducing some ideas
	for (int i = 0; i < ARRAY; i++)
	{
		if (i % 2 == 1)
		{
			pets[i] = new Dog();
			dynamic_cast<Dog*>(pets[i])->setIdea("salsisha", 0);
		}
		else
		{
			pets[i] = new Cat();
			dynamic_cast<Cat*>(pets[i])->setIdea("atun", 0);
		}
	}

	//	Testing each animal in the array
	for (int i = 0; i < ARRAY; i++)
	{
		std::cout << "\ni = " << i << " type = " << pets[i]->getType() << std::endl;
		if (i % 2 == 1)
			std::cout << dynamic_cast<Dog*>(pets[i])->getIdea(0) << std::endl;
		else
			std::cout << dynamic_cast<Cat*>(pets[i])->getIdea(0) << std::endl;
	}

	//	Copying a dog to test the deep copy
	Dog rufo(*dynamic_cast<Dog*>(pets[1]));

	//	Change one brain idea just to one clone
	rufo.setIdea("ya no quiero salshisha, ahora quiero ser feliz", 0);

	std::cout << "\n\nRufo dice: " << rufo.getIdea(0)
		<< "\nel otro perro dice: " << dynamic_cast<Dog*>(pets[1])->getIdea(0)
		<< "\n" << std::endl;

	//	Deleting OG dog
	delete (pets[1]);

	//	Testing with rufo after deleting the copied dog to test deep copy
	std::cout << "\n\nRufo vuelve a decir: " << rufo.getIdea(0) << "\n" << std::endl;

	//	Cleaning up memory (but OG dog who got deleted earlier)
	for (int i = 0; i < ARRAY; i++)
		if (i != 1)
			delete (pets[i]);
	delete[] (pets);
	return (0);
}
