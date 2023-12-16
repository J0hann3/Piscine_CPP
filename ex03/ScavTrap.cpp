/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:51:13 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 16:12:23 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor with string called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& ScavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_attackDamage = ScavTrap._attackDamage;
	_energyPoint = ScavTrap._energyPoint;
	_name = ScavTrap._name;
	_hitPoint = ScavTrap._hitPoint;
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

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoint < 1)
		return ;
	_energyPoint--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" <<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate keeper mode now." << std::endl;
}