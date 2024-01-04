/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:36:32 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:41:19 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor call" << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog const &Dog)
{
	std::cout << "Dog copy constructor call" << std::endl;
	_brain = new Brain();
	*_brain = *Dog._brain;
	type = Dog.type;
}

Dog & Dog::operator=(Dog const & Dog)
{
	*_brain = *Dog._brain;
	type = Dog.type;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor call" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woofffff !!!" << std::endl;
}