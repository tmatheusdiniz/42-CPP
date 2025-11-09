/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:04:56 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/28 14:06:39 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
	ClapTrap soldier("soldier boy");
	soldier.attack("homelander");
	ScavTrap superSoldier;
	superSoldier.attack("soldier boy");
	superSoldier.setGuardGate(true);
	superSoldier.guardGate();
	FragTrap anotherSoldier;
	anotherSoldier.attack("soldier Boy");
}
