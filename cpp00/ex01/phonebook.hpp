/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:29:33 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:29:24 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <cstdlib>
# include <limits>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		current;
	int		amount;
	
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
};

#endif
