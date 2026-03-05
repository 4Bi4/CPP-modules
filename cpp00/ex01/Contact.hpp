/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:28:41 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/05 17:51:03 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void setFirstName(const std::string &firstName);
	std::string getFirstName() const;
	void setLastName(const std::string &lastName);
	std::string getLastName() const;
	void setNickname(const std::string &nickname);
	std::string getNickname() const;
	void setPhoneNumber(const std::string &phoneNumber);
	std::string getPhoneNumber() const;
	void setDarkestSecret(const std::string &darkestSecret);
	std::string getDarkestSecret() const;
};

#endif
