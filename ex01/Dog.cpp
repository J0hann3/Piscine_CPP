/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:36:32 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 13:21:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructor call" << std::endl;
}

Dog::Dog(Dog const &Dog)
{
	_brain = new Brain();
	*_brain = *Dog._brain;
	type = Dog.type;
	std::cout << "Dog copy constructor call" << std::endl;
}

Dog const & Dog::operator=(Dog const & Dog)
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