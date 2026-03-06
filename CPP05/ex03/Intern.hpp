/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:18:05 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/20 20:51:13 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator = (const Intern &src);
		AForm *makeForm(std::string formName, std::string target);
		class FormNotExist : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
