/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:50:26 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 19:10:24 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL){}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() <<std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}