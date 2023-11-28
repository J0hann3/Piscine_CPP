/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:32 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/28 18:42:19 by jvigny           ###   ########.fr       */
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
	return 0;
}