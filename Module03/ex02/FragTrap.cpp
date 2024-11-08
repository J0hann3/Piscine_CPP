/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:09:03 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 17:15:19 by jvigny           ###   ########.fr       */
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
	this->ClapTrap::operator=(FragTrap);
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
