/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:51:13 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/09 20:32:28 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// _name = name;
	std::cout << "ScavTrap constructor with string called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& ScavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = ScavTrap;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & ScavTrap)
{
	std::cout << "ScavTrap copy assignment operator called" <<std::endl;
	_name = ScavTrap._name;
	_hitPoint = ScavTrap._hitPoint;
	_energyPoint = ScavTrap._energyPoint;
	_attackDamage = ScavTrap._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}