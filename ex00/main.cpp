/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:21:30 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/09 19:47:20 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Quentin("Quentin");
	ClapTrap Alex;
	ClapTrap Alexandre("Alexandre");

	Alexandre.attack("Alex");
	Alex.takeDamage(Alexandre.getAttackDamage());
	Alex.beRepaired(10);

	Quentin.setAttackDamage(7);
	Quentin.attack("Alexandre");
	Alexandre.takeDamage(Quentin.getAttackDamage());

	Alexandre.beRepaired(1);

	Quentin.attack("Alexandre");
	Alexandre.takeDamage(Quentin.getAttackDamage());

	Alex.setAttackDamage(2);
	Alex.attack("Alexandre");
	Alexandre.takeDamage(Alex.getAttackDamage());

	return 0;
}