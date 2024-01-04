/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:11:57 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:30:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	_index = 0;
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(Brain const &Brain)
{
	std::cout << "Brain copy constructor" << std::endl;
	_index = Brain._index;
	for (int i = 0; i < _index; i++)
		_ideas[i] = Brain._ideas[i];
}

Brain & Brain::operator=(Brain const & Brain)
{
	std::cout << "Brain assignation operator" << std::endl;
	_index = Brain._index;
	for (int i = 0; i < _index; i++)
		_ideas[i] = Brain._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

// void Brain::addIdea(std::string idea)
// {
// 	if (_index >= 99)
// 	{
// 		std::cout << "Brain : array of ideas is full" << std::endl;
// 		return ;
// 	}
// 	_ideas[_index] = idea;
// 	_index++;
// }

// void Brain::printAllIdeas()
// {
// 	if (_index == 0)
// 		std::cout << "Empty array of ideas" << std::endl;
// 	for (int i = 0; i < _index; i++)
// 	{
// 		std::cout << _ideas[i] << std::endl;
// 	}
// }

// void Brain::modifieIdea(int i,std::string idea)
// {
// 	_ideas[i]=idea;
// }