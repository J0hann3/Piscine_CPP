/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:20:57 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 18:53:00 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : _type("Default")
{}

AMateria::AMateria(std::string const & type) : _type(type)
{}

AMateria const & AMateria::operator=(AMateria const & materia)
{
	_type = materia._type;
	return (*this);
}

AMateria::~AMateria()
{}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Default use of Amateria on " << target.getName() << std::endl;
}
