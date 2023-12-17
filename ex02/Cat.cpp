/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:39 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 13:53:46 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat default constructor call" << std::endl;
}

Cat::Cat(Cat const &Cat)
{
	type = Cat.type;
	_brain = new Brain();
	*_brain = *Cat._brain;
	std::cout << "Cat copy constructor call" << std::endl;
}

Cat const & Cat::operator=(Cat const & Cat)
{
	*_brain = *Cat._brain;
	type = Cat.type;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor call" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaouhhhh" << std::endl;
}
