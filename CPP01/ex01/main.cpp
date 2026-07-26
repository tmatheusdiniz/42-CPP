/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:22:46 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/19 16:54:22 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(5, "darksquad");
	Zombie* hordeNonSense = zombieHorde(3, "herewego");

	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	horde[3].announce();
	horde[4].announce();
	std::cout << "hello?" << std::endl;
	hordeNonSense[2].announce();
	delete[] horde;
	delete[] hordeNonSense;
}
