/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:27:43 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/04 14:56:03 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int16_t _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int16_t grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat &src);

		std::string getName() const;
		int16_t getGrade() const;
		void incrementBureaucratLevel();
		void decrementBureaucratLevel();
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
