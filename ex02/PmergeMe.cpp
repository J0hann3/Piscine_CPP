/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:53:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/28 19:20:51 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(std::vector<unsigned int>()), _list(std::list<unsigned int>())
{}

PmergeMe::PmergeMe(PmergeMe const & copy) : _vector(std::vector<unsigned int>(copy._vector)),
			_list(std::list<unsigned int>(copy._list))
{}

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


void PmergeMe::merge_insert_vector(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end)
{
	if (std::distance(start, end) < 2)
		return;
	int middle = std::distance(start, end) / 2;
	merge_insert_vector(start, start + middle);
	merge_insert_vector(start + middle, end);
	std::vector<unsigned int> res;
	std::vector<unsigned int>::iterator it_start = start;
	std::vector<unsigned int>::iterator it_middle = start + middle;
	while (it_middle != end && it_start != start + middle)
	{
		if (*it_start < *it_middle)
		{
			res.push_back(*it_start);
			it_start++;
		}
		else
		{
			res.push_back(*it_middle);
			it_middle++;
		}
	}
	while (it_middle != end)
		res.push_back(*(it_middle)++);
	while (it_start != start + middle)
		res.push_back(*(it_start)++);
	std::swap_ranges(start, end, res.begin());
}

void PmergeMe::merge_insert_list(std::list<unsigned int>::iterator start, std::list<unsigned int>::iterator end)
{
	if (std::distance(start, end) < 2)
		return;
	int middle = std::distance(start, end) / 2;
	std::list<unsigned int>::iterator it_middle = start;
	for(int i = 0; i < middle; i++)
		it_middle++;
	merge_insert_list(start, it_middle);
	merge_insert_list(it_middle, end);
	std::list<unsigned int> res;
	std::list<unsigned int>::iterator it_start = start;
	std::list<unsigned int>::iterator it_m = it_middle;
	while (it_m != end && it_start != it_middle)
	{
		if (*it_start < *it_m)
		{
			res.push_back(*it_start);
			it_start++;
		}
		else
		{
			res.push_back(*it_m);
			it_m++;
		}
	}
	while (it_m != end)
		res.push_back(*(it_m)++);
	while (it_start != it_middle)
		res.push_back(*(it_start)++);
	std::swap_ranges(start, end, res.begin());
}

void PmergeMe::merge(int argc, char **argv)
{
	struct timespec start, end;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	fill_vector_container(argc, argv);
	// merge_insert_vector(_vector.begin(), _vector.end());
	merge_insert_vector2();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	double timeVector = (end.tv_sec - start.tv_sec) * 1e6 + ((end.tv_nsec - start.tv_nsec) / 1000.0);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	fill_list_container(argc, argv);
	merge_insert_list(_list.begin(), _list.end());
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	double timeList = (end.tv_sec - start.tv_sec) * 1e6 + ((end.tv_nsec - start.tv_nsec) / 1000.0);

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::vector<unsigned int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector :" << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list :" << timeList << " us" << std::endl;
}

static void sort_pair(std::vector<std::pair<unsigned int, unsigned int> >& tab)
{
	if (tab.size() < 2)
		return;
	size_t mid = tab.size() / 2;
	std::vector<std::pair<unsigned int, unsigned int> > left(tab.begin(), tab.begin() + mid);
	std::vector<std::pair<unsigned int, unsigned int> > right(tab.begin() + mid, tab.end());
	sort_pair(left);
	sort_pair(right);
	size_t index = 0;
	size_t index_left = 0;
	size_t index_right = 0;
	while(index_left < left.size() && index_right < right.size())
	{
		if (left[index_left].second < right[index_right].second)
			tab[index++] = left[index_left++];
		else
			tab[index++] = right[index_right++];
	}
	while(index_left < left.size())
		tab[index++] = left[index_left++];
	while(index_right < right.size())
		tab[index++] = right[index_right++];
}

static void dichotomie(std::vector<unsigned int> & res, unsigned int value)
{
	int start = 0;
	int end = res.size() - 1;
	while (1)
	{
		int middle = (end - start) / 2;
		if (middle == 0)
		{
			res.insert(res.begin() + start + 1, value);
			return ;
		}
		else if (value > res[start + middle])
			start += middle;
		else
			end = start + middle;
	}
}

void PmergeMe::merge_insert_vector2()
{
	std::vector<std::pair<unsigned int, unsigned int> > tab;
	for (unsigned int i = 0; i + 2 <= _vector.size(); i+=2)
	{
		if (_vector[i] < _vector[i + 1])
			tab.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		else
			tab.push_back(std::make_pair(_vector[i + 1], _vector[i]));
	}
	sort_pair(tab);
	std::vector<unsigned int> res;
	res.push_back(tab[0].first);
	for (unsigned int i = 0; i < tab.size(); i++)
		res.push_back(tab[i].second);
	for (unsigned int i = 1; i + 2 <= tab.size(); i+=2)
	{
		dichotomie(res, tab[i + 1].first);
		dichotomie(res, tab[i].first);
	}
	if (_vector.size() % 2 != 0)
		dichotomie(res, _vector.back());
}