/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:32 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 13:14:16 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	int nb(15);
	Zombie* horde = zombieHorde(nb, "Zombie");
	if (horde == NULL)
		return 1;
	for (int i = 0; i < nb; i++)
	{
		horde[i].announce();
	}
	delete [] horde;

	nb = 1;
	horde = zombieHorde(nb, "Zombie_one");
	if (horde == NULL)
		return 1;
	for (int i = 0; i < nb; i++)
	{
		horde[i].announce();
	}
	delete [] horde;

	nb = 0;
	horde = zombieHorde(nb, "Zombie_zero");
	if (horde == NULL)
		return 1;
	for (int i = 0; i < nb; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}