/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:36:32 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:24:19 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor call" << std::endl;
}

Dog::Dog(Dog const &Dog)
{
	type = Dog.type;
	std::cout << "Dog copy constructor call" << std::endl;
}

Dog & Dog::operator=(Dog const & Dog)
{
	type = Dog.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor call" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woofffff !!!" << std::endl;
}