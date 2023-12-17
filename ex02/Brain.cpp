/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:11:57 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 14:14:31 by jvigny           ###   ########.fr       */
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

Brain const & Brain::operator=(Brain const & Brain)
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
