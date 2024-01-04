/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:39 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:30:34 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor call" << std::endl;
}

WrongCat::WrongCat(WrongCat const &WrongCat)
{
	type = WrongCat.type;
	std::cout << "WrongCat copy constructor call" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & WrongCat)
{
	type = WrongCat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor call" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Cocoricoooo !!!" << std::endl;
}
