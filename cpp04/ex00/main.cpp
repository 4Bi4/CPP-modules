/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:30:31 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/23 22:09:45 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int	main()
{
	const Animal* ditto = new Animal();
	const Animal* garfield = new Cat();
	const Animal* rufo = new Dog();

	const WrongAnimal* guamedo = new WrongAnimal();
	const WrongAnimal* guameda = new WrongCat();

	std::cout << "\nHonest to god animal testing:\n" << std::endl;
	std::cout << ditto->getType() << " says: ";
	ditto->makeSound();
	std::cout << garfield->getType() << " says: ";
	garfield->makeSound();
	std::cout << rufo->getType() << " says: ";
	rufo->makeSound();

	std::cout << "\nVegan testing (not real animals):\n" << std::endl;
	std::cout << guamedo->getType() << " says: ";
	guamedo->makeSound();
	std::cout << guameda->getType() << " says: ";
	guameda->makeSound();

	std::cout << std::endl;

	delete (ditto);
	delete (garfield);
	delete (rufo);
	delete (guamedo);
	delete (guameda);
	return (0);
}