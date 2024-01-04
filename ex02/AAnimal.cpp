/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:18 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:36:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Default")
{
	std::cout << "Animal default constructor call" << std::endl;
}

AAnimal::AAnimal(std::string type): type(type)
{
	std::cout << "Animal type constructor call" << std::endl;
}

AAnimal::AAnimal(AAnimal const &animal)
{
	std::cout << "Animal copy constructor call" << std::endl;
	type = animal.type;
}

AAnimal & AAnimal::operator=(AAnimal const & animal)
{
	type = animal.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor call" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}
