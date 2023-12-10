/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:50:32 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/10 20:03:48 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor with string called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" <<std::endl;
	_name = clapTrap._name;
	_hitPoint = clapTrap._hitPoint;
	_energyPoint = clapTrap._energyPoint;
	_attackDamage = clapTrap._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoint < 1)
		return ;
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take damage, he's dead" << std::endl;
		return ;
	}
	_hitPoint -= amount;
	if (_hitPoint < 0)
	{
		_hitPoint = 0;
		std::cout << "ClapTrap " << _name << " take damage. He's dead !!"<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " take damage and lose " << amount << " hit point." <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint < 1)
		return ;
	std::cout << "ClapTrap " << _name << " repairs itself and gets " << amount << " hit point." <<std::endl;
	_energyPoint--;
	_hitPoint += amount;
}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}
