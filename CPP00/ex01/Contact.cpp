/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:19:21 by mreinald          #+#    #+#             */
/*   Updated: 2025/09/27 16:19:54 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickName() const
{
	return (this->_nickName);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

void Contact::setFiritsName(const std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(const std::string &nickName)
{
	this->_nickName = nickName;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
