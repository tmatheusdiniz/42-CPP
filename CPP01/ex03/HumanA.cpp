/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:56:13 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/20 23:17:00 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& _name, Weapon& _weapon) 
    : _name(_name), _weapon(_weapon)
{

}

void HumanA::attack()
{
	std::cout << _name << " attacks with their "
		<< _weapon.getType() << std::endl;
}
