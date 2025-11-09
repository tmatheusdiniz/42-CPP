/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:13:38 by mreinald          #+#    #+#             */
/*   Updated: 2025/09/24 10:47:21 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook()
{
	this->_counter = 0;
	this->_oldestIndex = 0;
}

PhoneBook::~PhoneBook ()
{
	
}

int PhoneBook::getCounter()
{
	return (this->_counter);
}

void PhoneBook::setCounter(int newCounter)
{
	this->_counter = newCounter;
}

std::string formatString(const std::string& str)
{
	std::string parsed;

	if (str.length() > 10)
		parsed = str.substr(0, 9) + ".";
	else
	{
		parsed = std::string(10, ' ');
		int position = 10 - str.length();
		for (size_t i = 0; i < str.length(); i ++)
			parsed[position + i] = str[i];
	}
	return (parsed);
}

void PhoneBook::addContact(const Contact contact)
{
	this->_contacts[_oldestIndex] = contact;
	if (_counter < 8)
		_counter ++;
	_oldestIndex = (_oldestIndex + 1) % 8;
	std::cout << BLUE << "Contact sucessfully added" << DEFAULT << std::endl;
}

void PhoneBook::displayOneContact(int index) const
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|      Contact Informations                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "| First Name:     " << this->_contacts[index].getFirstName()
		<< std::endl;
	std::cout << "| Last Name:      " << this->_contacts[index].getLastName()
		<< std::endl;
	std::cout << "| Nickname:       " << this->_contacts[index].getNickName()
		<< std::endl;
	std::cout << "| Phone Number:   " << this->_contacts[index].getPhoneNumber()
		<< std::endl;
	std::cout << "| Darkest Secret: " << this->_contacts[index].getDarkestSecret()
		<< std::endl;
	std::cout << "|___________________________________________|" << std::endl;
}

void PhoneBook::displayAllContacts() const
{
	std::cout <<" ___________________________________________"<< std::endl;
	std:: cout <<"|     Index|First Name| Last Name| Nick Name| "<< std::endl;
	std:: cout <<"|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_counter; i ++)
	{
		std::cout << "|" << std::setw(10) << (i + 1) << "|";
		std:: cout << formatString(this->_contacts[i].getFirstName()) << "|";
		std:: cout << formatString(this->_contacts[i].getLastName()) << "|";
		std:: cout << formatString(this->_contacts[i].getNickName()) << "|"
		<< std::endl;
	}
	std:: cout <<"|___________________________________________|" << std::endl;
}
