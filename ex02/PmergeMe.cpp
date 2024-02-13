/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:53:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/13 14:33:18 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector(std::vector<unsigned int>()), _deque(std::deque<unsigned int>())
{}

PmergeMe::PmergeMe(PmergeMe const & copy) : _vector(std::vector<unsigned int>(copy._vector)),
			_deque(std::deque<unsigned int>(copy._deque))
{}

PmergeMe & PmergeMe::operator=(PmergeMe const & assign)
{
	_vector = assign._vector;
	_deque = assign._deque;
	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::merge(int argc, char **argv)
{
	struct timespec start, end;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	merge_insert_vector(argc, argv);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
	
	double timeVector = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_nsec - start.tv_nsec) / 1.e6);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	merge_insert_deque(argc, argv);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	double timeDeque = (end.tv_sec - start.tv_sec) * 1000 + ((end.tv_nsec - start.tv_nsec) / 1.e6);

	printRes(argc, argv, timeVector, timeDeque);
}

void PmergeMe::printRes(int argc, char **argv, double timeVector, double timeDeque)
{
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
	// std::cout << "After: ";
	// for (unsigned int i = 0; i < _deque.size(); i++)
	// {
	// 	std::cout << _deque[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << timeVector << " ms" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << timeDeque << " ms" << std::endl;
}

template<typename T>
static void sort_pair(T& tab)
{
	if (tab.size() < 2)
		return;
	size_t mid = tab.size() / 2;
	T left(tab.begin(), tab.begin() + mid);
	T right(tab.begin() + mid, tab.end());
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

template<typename T>
static void dichotomie(T & res, unsigned int value)
{
	if (res.size() == 0)
	{
		res.push_back(value);
		return ;
	}
	int start = 0;
	int end = res.size();
	while (1)
	{
		int middle = (end - start) / 2;
		if (middle == 0)
		{
			if (value > res[start + middle])
				res.insert(res.begin() + start + 1, value);
			else
				res.insert(res.begin() + start, value);
			return ;
		}
		else if (value > res[start + middle])
			start += middle;
		else
			end = start + middle;
	}
}

static unsigned int atoui(char * str)
{
	unsigned int res = 0;

	if (str == NULL || std::isdigit(str[0]) == 0)
		throw std::invalid_argument("Invalid argument");
	for (int i = 0; i < str[i]; i++)
	{
		if (std::isdigit(str[i]) == 0)
			throw std::invalid_argument("Invalid argument");
		if (res > (UINT_MAX + '0' - str[i]) / 10)
			throw std::out_of_range("Overflow of unsigned int");
		res = res * 10 + str[i] - '0';
	}
	return res;
}

template<typename T>
static long create_pairs(int argc, char **argv, T &tab)
{
	unsigned int tmp;
	unsigned int tmp1;
	for (int i = 1; i + 2 <= argc; i+=2)
	{
		tmp = atoui(argv[i]);
		tmp1 = atoui(argv[i + 1]);
		if (tmp < tmp1)
			tab.push_back(std::make_pair(tmp, tmp1));
		else
			tab.push_back(std::make_pair(tmp1, tmp));
	}
	if (argc % 2 == 0)
		return atoui(argv[argc - 1]);
	return -1;
}

void PmergeMe::merge_insert_vector(int argc, char **argv)
{
	std::vector<std::pair<unsigned int, unsigned int> > tab;
	long last = create_pairs(argc, argv, tab);
	sort_pair(tab);
	_vector.clear();
	if (tab.size() != 0)
		_vector.push_back(tab[0].first);
	for (unsigned int i = 0; i < tab.size(); i++)
		_vector.push_back(tab[i].second);
	for (unsigned int i = 1; i + 2 <= tab.size(); i+=2)
	{
		dichotomie(_vector, tab[i + 1].first);
		dichotomie(_vector, tab[i].first);
	}
	if (tab.size() > 1 && tab.size() % 2 == 0)
		dichotomie(_vector, tab.back().first);
	if (last != -1)
		dichotomie(_vector, last);
}

void PmergeMe::merge_insert_deque(int argc, char **argv)
{
	std::deque<std::pair<unsigned int, unsigned int> > tab;
	long last = create_pairs(argc, argv, tab);
	sort_pair(tab);
	_deque.clear();
	if (tab.size() != 0)
		_deque.push_back(tab[0].first);
	for (unsigned int i = 0; i < tab.size(); i++)
		_deque.push_back(tab[i].second);
	for (unsigned int i = 1; i + 2 <= tab.size(); i+=2)
	{
		dichotomie(_deque, tab[i + 1].first);
		dichotomie(_deque, tab[i].first);
	}
	if (tab.size() > 1 && tab.size() % 2 == 0)
		dichotomie(_deque, tab.back().first);
	if (last != -1)
		dichotomie(_deque, last);
}