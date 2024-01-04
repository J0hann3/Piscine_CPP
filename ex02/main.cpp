/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 14:40:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap Quentin("Quentin");
	FragTrap Alex;
	FragTrap Alexandre("Alexandre");

	std::cout << std::endl;

	Alexandre.attack("Alex");
	Alex.takeDamage(Alexandre.getAttackDamage());
	Alex.beRepaired(10);

	std::cout << std::endl;
	for (int i = 0; i < 12; i++)
	{
		Quentin.attack("Alexandre");
		Alexandre.takeDamage(Quentin.getAttackDamage());
	}
	std::cout << std::endl;

	Quentin.beRepaired(1);

	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());

	Alex.highFivesGuys();
	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());
	
	std::cout << std::endl;

	return 0;
}