/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:45:26 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 19:06:00 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon): name(name), weapon(weapon){}

void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
}