/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:09:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/10 20:20:55 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor with string called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& FragTrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = FragTrap;
}

FragTrap& FragTrap::operator=(FragTrap const & FragTrap)
{
	std::cout << "FragTrap copy assignment operator called" <<std::endl;
	_name = FragTrap._name;
	_hitPoint = FragTrap._hitPoint;
	_energyPoint = FragTrap._energyPoint;
	_attackDamage = FragTrap._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : High Fives !" << std::endl;
}
