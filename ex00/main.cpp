/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 14:27:27 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap Quentin("Quentin");
	ClapTrap Alex;
	ClapTrap Alexandre("Alexandre");

	std::cout << std::endl;

	Alexandre.attack("Alex");
	Alex.takeDamage(Alexandre.getAttackDamage());
	Alex.beRepaired(10);

	std::cout << std::endl;
	Quentin.setAttackDamage(3);
	for (int i = 0; i < 12; i++)
	{
		Quentin.attack("Alexandre");
		Alexandre.takeDamage(Quentin.getAttackDamage());
	}
	std::cout << std::endl;

	Quentin.beRepaired(1);

	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());

	Alex.setAttackDamage(2);
	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());
	Alex.beRepaired(0);

	return 0;
}