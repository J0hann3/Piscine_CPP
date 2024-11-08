/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:18 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:24:25 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "WrongAnimal default constructor call" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "WrongAnimal type constructor call" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &Wronganimal)
{
	std::cout << "WrongAnimal copy constructor call" << std::endl;
	type = Wronganimal.type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & Wronganimal)
{
	type = Wronganimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor call" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default sound for WrongAnimal" << std::endl;
}
