/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:53:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/25 20:40:15 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(std::vector<unsigned int>()), _list(std::list<unsigned int>())
{}

// PmergeMe(unsigned int size) : _vector(std::vector<unsigned int>(size)), _list(std::list<unsigned int>(size))
// {}

PmergeMe::PmergeMe(PmergeMe const & copy) : _vector(std::vector<unsigned int>(copy._vector)),
			_list(std::list<unsigned int>(copy._list)){}

PmergeMe & PmergeMe::operator=(PmergeMe const & assign)
{
	_vector = assign._vector;
	_list = assign._list;
	return *this;
}

PmergeMe::~PmergeMe()
{}

static unsigned int atoui(char * str)
{
	unsigned int res = 0;

	if (str == NULL || std::isdigit(str[0]) == 0)
		throw std::invalid_argument("Invalid argument");
	for (int i = 0; i < str[i] && std::isdigit(str[i]) != 0; i++)
	{
		if (res > (UINT_MAX + '0' - str[i]) / 10)
			throw std::out_of_range("Overflow of unsigned int");
		res = res * 10 + str[i] - '0';
	}
	return res;
}

void PmergeMe::fill_vector_container(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		unsigned int tmp = atoui(argv[i]);
		if (std::find(_vector.begin(), _vector.end(), tmp) != _vector.end())
			throw std::invalid_argument("Duplicate argument");
		_vector.push_back(tmp);
	}
}

void PmergeMe::fill_list_container(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		unsigned int tmp = atoui(argv[i]);
		if (std::find(_list.begin(), _list.end(), tmp) != _list.end())
			throw std::invalid_argument("Duplicate argument");
		_list.push_back(tmp);
	}
}

void PmergeMe::merge_insert_vector()
{
	
}

void PmergeMe::merge_insert_list()
{}
