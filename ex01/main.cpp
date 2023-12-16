/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/10 20:20:10 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap Quentin("Quentin");
	ScavTrap Alex;
	ScavTrap Alexandre("Alexandre");

	Alexandre.guardGate();
	Alexandre.attack("Alex");
	Alex.takeDamage(Alexandre.getAttackDamage());
	Alex.beRepaired(10);

	Quentin.attack("Alexandre");
	Alexandre.takeDamage(Quentin.getAttackDamage());

	Alexandre.beRepaired(1);

	Quentin.attack("Alexandre");
	Alexandre.takeDamage(Quentin.getAttackDamage());

	Alex.attack("Alexandre");
	Alexandre.takeDamage(Alex.getAttackDamage());

	return 0;
}