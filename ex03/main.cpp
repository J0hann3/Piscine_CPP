/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 17:13:27 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap Test("coucou");
	// DiamondTrap hello(Test);
	// std::cout<<sizeof(DiamondTrap)<<std::endl;
	// std::cout<<sizeof(ScavTrap)<<std::endl;
	// std::cout<<sizeof(FragTrap)<<std::endl;
	// std::cout<<sizeof(ClapTrap)<<std::endl;
	DiamondTrap Quentin(Test);
	DiamondTrap Alex;
	DiamondTrap Alexandre("Alexandre");

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

	Quentin.whoAmI();
	Alex.attack("Quentin");
	Quentin.takeDamage(Alex.getAttackDamage());
	
	std::cout << std::endl;

	return 0;
}