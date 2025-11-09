/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:58:02 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/19 16:43:56 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	int i = 0;
	Zombie* horde = new Zombie[N];

	while (i < N)
	{
		horde[i].setName(name + " @" + std::to_string(i + 1));
		i ++;
	}
	return (horde);
}
