/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:20:37 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/11 19:18:01 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char * Span::SpanFullException::what() const throw()
{
	return ("Span is full, can't add new element");
}

const char * Span::NotEnoughNumberException::what() const throw()
{
	return ("Span doesn't contain enough argument");
}

Span::Span() : _tab(), _size(0)
{}

Span::Span(unsigned int size) : _tab(), _size(size)
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

unsigned int Span::shortestSpan() const
{
	if (_tab.size() < 2)
		throw Span::NotEnoughNumberException();
	std::vector<int> tmp(_tab.begin(), _tab.end());
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin(), tmp.end());
}

unsigned int Span::longestSpan() const
{
	if (_tab.size() < 2)
		throw Span::NotEnoughNumberException();
	return (*std::max_element(_tab.begin(), _tab.end()) - *std::min_element(_tab.begin(), _tab.end()));
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
