/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:20:37 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/20 19:17:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream> 

const char * Span::SpanFullException::what() const throw()
{
	return ("Span is full, can't add new element");
}

const char * Span::NotEnoughNumberException::what() const throw()
{
	return ("Span doesn't contain enough argument");
}

Span::Span() : _size(0)
{}

Span::Span(unsigned int size) : _size(size)
{}

Span::Span(Span const & copy) : _tab(copy._tab.begin(), copy._tab.end()), _size(copy._size)
{}

Span & Span::operator=(Span const &assign)
{
	_size = assign._size;
	_tab = assign._tab;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_tab.size() + 1 > _size)
		throw Span::SpanFullException();
	_tab.push_back(number);
}

static int diff_adajacent(int const & number, int const & number1)
{
	return ((number - number1 > 0) ? number - number1 : -(number - number1));
}

unsigned int Span::shortestSpan() const
{
	std::vector<int> res(_tab.size() - 1, 0);

	if (_tab.size() < 2)
		throw Span::NotEnoughNumberException();
	std::transform(_tab.begin(), _tab.end() - 1, _tab.begin() + 1, res.begin(), diff_adajacent);
	return *std::min_element(res.begin(), res.end());
}

unsigned int Span::longestSpan() const
{
	std::vector<int> res(_tab.size() - 1, 0);

	if (_tab.size() < 2)
		throw Span::NotEnoughNumberException();
	std::transform(_tab.begin() + 1, _tab.end(), _tab.begin(), res.begin(), diff_adajacent);
	return *std::max_element(res.begin(), res.end());
}

void Span::print() const
{
	for (std::vector<int>::const_iterator it = _tab.begin(); it != _tab.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (std::distance(first, last) + _tab.size() > _size)
		throw Span::SpanFullException();
	_tab.insert(_tab.end(), first, last);
}
