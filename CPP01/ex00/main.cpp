/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:10:25 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/19 00:21:43 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("mrrobot");
	zombie->announce();
	randomChump("mrrobot00000001");
	delete zombie;
	return (0);
}
