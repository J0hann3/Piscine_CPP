/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:47:33 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 19:09:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public :
	HumanB(std::string name);
	void attack(void) const;
	void setWeapon(Weapon weapon);
private :
	std::string name;
	Weapon* weapon;
};

#endif