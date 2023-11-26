/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:40:39 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 18:26:23 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": is destroyed" <<std::endl;
}

void Zombie::setName(std::string str)
{
	this->name = str;
}