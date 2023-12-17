/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:14:29 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 18:22:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream> 

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(Cure const & copy)
{
	_type = copy.getType();
}

Cure const & Cure::operator=(Cure const & materia)
{
	_type = materia.getType();
	return (*this);
}

Cure::~Cure()
{}

Cure* Cure::clone() const
{
	Cure *res = new Cure(*this);
	return res;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
