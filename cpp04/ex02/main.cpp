/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:11:19 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/25 06:23:57 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Cant instance animal (abstract class)
	// Animal* test = new Animal();

	//	testing with cats
	Cat* mew = new Cat();
	mew->setIdea("que pesado el giovanni", 0);
	Cat* mewtwo = new Cat(*mew);

	//	same idea different brain
	std::cout << "\nMew dice: " << mew->getIdea(0) << "\nMewtwo dice: " << mewtwo->getIdea(0) << std::endl;
	
	//	change just one brain
	mewtwo->setIdea("bola sombra pa ti", 0);
	
	//	testing that the brains are different
	std::cout << "\nMew dice: " << mew->getIdea(0) << "\nMewtwo dice: " << mewtwo->getIdea(0) << std::endl;

	std::cout << "\n-----------------------------\n" << std::endl;
	//	now with dogs
	Dog* entei = new Dog();
	entei->setIdea("lo que daría por un hueso ahora mismo", 0);
	Dog* suicune = new Dog(*entei);
	
	//	same idea different brain
	std::cout << "\nEntei dice: " << entei->getIdea(0) << "\nSuicune dice: " << suicune->getIdea(0) << std::endl;

	//	change just one brain
	suicune->setIdea("hmmmm costillas", 0);
	
	//	final test
	std::cout << "\nEntei dice: " << entei->getIdea(0) << "\nSuicune dice: " << suicune->getIdea(0) << std::endl;
	
	std::cout << std::endl;
	delete (mew);
	delete (mewtwo);
	delete (entei);
	delete (suicune);
	return (0);
}
