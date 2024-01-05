/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:40:27 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/05 16:56:18 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
		_is_empty[i] = true;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_is_empty[i] = true;
}


Character::Character(Character const & copy)
{
	_name = copy._name;
	for (int i = 0; i < 4; i++)
		_is_empty[i] = copy._is_empty[i];
	for (int i = 0; i < 4; i++)
		if (!_is_empty[i])
			_inventory[i] = copy._inventory[i]->clone();
}

Character & Character::operator=(Character const & character)
{
	for (int i = 0; i < 4; i++)
		if (!_is_empty[i])
			delete _inventory[i];
	_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		_is_empty[i] = character._is_empty[i];
		if (!_is_empty[i])
			_inventory[i] = character._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (!_is_empty[i])
			delete _inventory[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int error = true;
	for (int i = 0; i < 4; i++)
	{
		if (_is_empty[i])
		{
			_inventory[i] = m;
			_is_empty[i] = false;
			error = false;
			return ;
		}
	}
	if (error)
		std::cout << "Character inventory if full, nothing can be add" << std::endl;
	// delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0 || _is_empty[idx])
	{
		std::cout << "Character inventory " << idx << " is empty, it can't be unequip" << std::endl;
		return;
	}
	_is_empty[idx] = true;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || _is_empty[idx])
	{
		std::cout << "Character inventory " << idx << " is empty, it can't be use" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
