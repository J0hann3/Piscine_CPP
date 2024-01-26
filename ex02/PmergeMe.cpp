/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:53:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/26 17:57:44 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(std::vector<unsigned int>()), _list(std::list<unsigned int>()),
	_resV(std::vector<std::vector<unsigned int>::iterator>())//, _resL(std::list<unsigned int>())
{}

PmergeMe::PmergeMe(PmergeMe const & copy) : _vector(std::vector<unsigned int>(copy._vector)),
			_list(std::list<unsigned int>(copy._list)), _resV(std::vector<std::vector<unsigned int>::iterator>(copy._resV)){}//,
			//_resL(std::list<unsigned int>()){}

PmergeMe & PmergeMe::operator=(PmergeMe const & assign)
{
	_vector = assign._vector;
	_list = assign._list;
	_resV = assign._resV;
	// _resL = assign._resL;
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

unsigned int PmergeMe::getSizeVector() const
{
	return (_vector.size());
}

static void swap(std::vector<unsigned int>::iterator &it, int iter)
{
	swap_ranges(it, (it + (iter / 2)), (it + (iter / 2)));
}

static void dichotomie(unsigned int add)
{
	while(1)
	{

	}
}

void PmergeMe::merge_insert_vector(unsigned int iter)
{
	if (_vector.size() < iter)
		return ;
	//make pairs
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it + iter < _vector.end(); it = it + iter)
	{
		std::cout << *(it + (iter / 2) - 1) << " " << *(it + iter - 1) << std::endl;
		if (*(it + (iter / 2) - 1) > *(it + iter - 1))
			swap(it, iter);
	}
	print();
	//sort pairs
	merge_insert_vector(iter * 2);
	std::cout <<"insert" << std::endl;
	print();
	//fill res vector
	_resV.push_back(_vector.begin() + (iter / 2) - 1);
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it + iter < _vector.end(); it = it + iter)
		_resV.push_back((it + iter - 1));
	printresV();

	std::vector<unsigned int>::iterator it = _vector.begin() + iter;
	while (it + iter / 2 <= _vector.end())
	{
		if (it + iter + iter / 2 <= _vector.end())
		{
			dichotomie(unsigned int add);//it + iter / 2 - 1
			dichotomie(unsigned int add);//it + iter - 1
		}
		else
			dichotomie(it, iter, ); //it + iter / 2 - 1

	}
	

	//insert elem
	

	
}

void PmergeMe::merge_insert_list()
{

}

void PmergeMe::printresV() const
{
	for (std::vector<unsigned int>::const_iterator it = _resV.begin(); it != _resV.end(); it = it + 1)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print() const
{
	for (std::vector<unsigned int>::const_iterator it = _vector.begin(); it != _vector.end(); it = it + 1)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
