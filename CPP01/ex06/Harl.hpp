/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:42:34 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/24 10:24:15 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define BOLD_RED "\033[1;32m"
#define GREEN "\033[32m"
#define BOLD_GREEN "\033[1;31m"
#define CYAN "\033[36m"
#define BOLD_CYAN "\033[1;36m"
#define DEFAULT "\033[0m"

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
};

#endif
