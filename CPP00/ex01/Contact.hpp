/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:51:33 by mreinald          #+#    #+#             */
/*   Updated: 2025/09/24 10:12:35 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _darkestSecret;
		std::string _phoneNumber;
	public:
		Contact();
		~Contact();
		// Getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getDarkestSecret() const;
		std::string getPhoneNumber() const;
		// Setters
		void setFiritsName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickName(const std::string& nickName);
		void setDarkestSecret(const std::string& darkestSecret);
		void setPhoneNumber(const std::string& phoneNumber);
};

#endif
