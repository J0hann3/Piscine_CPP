/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:55:32 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/20 19:17:17 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>
#include <typeinfo>

class Span
{
private:
	std::vector<int> _tab;
	unsigned int _size;
public:
	Span();
	Span(unsigned int size);
	Span(Span const & copy);
	Span & operator=(Span const &assign);
	~Span();
	void addNumber(int number);
	void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void print() const;
	class SpanFullException : public std::exception
	{
		virtual const char * what() const throw();
	};
	class NotEnoughNumberException : public std::exception
	{
		virtual const char * what() const throw();
	};
};

#endif