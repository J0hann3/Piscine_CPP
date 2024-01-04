/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 14:34:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap Quentin("Quentin");
	ScavTrap Alex;
	ScavTrap Alexandre("Alexandre");

	std::cout << std::endl;

	Alexandre.attack("Alex");
	Alex.takeDamage(Alexandre.getAttackDamage());
	Alex.beRepaired(10);

	std::cout << std::endl;
	for (int i = 0; i < 52; i++)
	{
		Quentin.attack("Alexandre");
		Alexandre.takeDamage(Quentin.getAttackDamage());
	}
	std::cout << std::endl;

	Quentin.beRepaired(1);

	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());

	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());
	
	std::cout << std::endl;

	return 0;
}