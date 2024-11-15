/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:14:39 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:49:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(Ice const & copy)
{
	_type = copy.getType();
}

Ice & Ice::operator=(Ice const & materia)
{
	_type = materia.getType();
	return (*this);
}

Ice::~Ice()
{}

Ice* Ice::clone() const
{
	Ice *res = new Ice(*this);
	return res;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
