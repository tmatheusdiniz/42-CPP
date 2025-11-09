/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:48 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/21 08:35:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club = Weapon("glock");

	HumanA mrMistery("mistery", club);
	mrMistery.attack();
	club.setType("some other type of glock");
	mrMistery.attack();
	HumanB mrm("Jim");
	mrm.attack();
	mrm.setWeapon(&club);
	mrm.attack();
	club.setType("i'm kind of trying");
	mrm.attack();
}
