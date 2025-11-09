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
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap soldierBoy("soldier boy");
	ScavTrap Homelander("Homelander");
	FragTrap starLight("Starlight");
	DiamondTrap butcher("Butcher");
	butcher.setGuardGate(true);
	butcher.takeDamage(30);
}
