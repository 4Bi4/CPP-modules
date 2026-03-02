/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:28:41 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/01 21:29:17 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string name;
	std::string number;

public:
	void setName(const std::string &name);
	std::string getName() const;
	void setNumber(const std::string &number);
	std::string getNumber() const;
};

#endif
