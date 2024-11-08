/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:14:16 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 17:13:39 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name")
{
	DiamondTrap::_name = "Default";
	ClapTrap::_energyPoint = ScavTrap::_enPoint;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	DiamondTrap::_name = name;
	ClapTrap::_energyPoint = ScavTrap::_enPoint;
	std::cout << "DiamondTrap constructor with string called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & diamond)
{
	std::cout << "DiamondTrap copy assignment operator called" <<std::endl;
	this->ScavTrap::operator=(diamond);
	this->FragTrap::operator=(diamond);
	DiamondTrap::_name = diamond.DiamondTrap::_name;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << DiamondTrap::_name << " ClapTrap name : " << ClapTrap::_name << std::endl;
}
