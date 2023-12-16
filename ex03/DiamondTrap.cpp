/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:14:16 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 18:51:55 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name"), _name("Default")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << "DiamondTrap constructor with string called" << std::endl;
	std::cout << this->ClapTrap::_attackDamage << std::endl;
	std::cout << this->FragTrap::_attackDamage << std::endl;
	std::cout << this->ScavTrap::_attackDamage << std::endl;
	std::cout << this->DiamondTrap::_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy)
{
	(void)copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & diamond)
{
	(void)diamond;
	return (*this);
}

void DiamondTrap::whoAmI()
{

}
