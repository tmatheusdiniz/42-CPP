/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:11:50 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/20 00:15:06 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
    	PresidentialPardonForm(const std::string& target);
    	PresidentialPardonForm(const PresidentialPardonForm& src);
    	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    	~PresidentialPardonForm();
		std::string getTarget() const;
    	void execute(Bureaucrat const& executor) const;
};

#endif
