/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:24:33 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 13:06:55 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z1 = newZombie("Zombie1");
	z1->announce();
	Zombie *z2 = newZombie("Zombie2");
	z2->announce();
	delete z1;
	delete z2;

	randomChump("Zombie3");
	randomChump("Zombie4");
}