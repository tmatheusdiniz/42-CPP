/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:37:51 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/15 10:27:01 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include "stdbool.h"
#include "string"
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int16_t _gradeToAssign;
		const int16_t _gradeToExecute;
	public:
		Form();
		Form(std::string name, bool isSigned, int16_t gradeToAssign,
			int16_t gradeToExecute);
		Form(const Form &src);
		~Form();
		Form &operator = (const Form &src);
		std::string getName() const;
		bool getIsSigned() const;
		int16_t getGradeToAssign() const;
		int16_t getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};

std::ostream &operator << (std::ostream &os, const Form &src);

#endif
