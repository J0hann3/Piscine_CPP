/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:18 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:24:02 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Default")
{
	std::cout << "Animal default constructor call" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
	std::cout << "Animal type constructor call" << std::endl;
}

Animal::Animal(Animal const &animal)
{
	std::cout << "Animal copy constructor call" << std::endl;
	type = animal.type;
}

Animal & Animal::operator=(Animal const & animal)
{
	type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor call" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Default sound for Animal" << std::endl;
}
