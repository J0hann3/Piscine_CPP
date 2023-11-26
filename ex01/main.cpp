/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:47:32 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 18:26:33 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main ()
{
	int nb(25);
	Zombie* horde = zombieHorde(nb, "Zombie");
	for (int i = 0; i < nb; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
}