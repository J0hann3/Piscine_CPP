/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:50:09 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:50:13 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

MateriaSource::MateriaSource() : _index(0), _max_size(4)
{}

MateriaSource::MateriaSource(MateriaSource const & copy) : _max_size(4)
{
	_index = copy._index;
	for (int i = 0; i < _index; i++)
		_source[i] = copy._source[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & materiaSource)
{
	_index = materiaSource._index;
	for (int i = 0; i < _index; i++)
		_source[i] = materiaSource._source[i];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _index; i++)
		delete _source[i];
}

void MateriaSource::learnMateria(AMateria* newAmateria)
{
	if (_index >= _max_size)
	{
		std::cout << "MateriaSource is full, you can't learn now ressources" << std::endl;
		delete newAmateria;
		return;
	}
	_source[_index] = newAmateria;
	_index++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _index; i++)
	{
		if (_source[i]->getType().compare(type) == 0)
		{
			return _source[i]->clone();
		}
	}
	return (NULL);
}
