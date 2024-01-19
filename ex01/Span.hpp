/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:55:32 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/19 20:03:16 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
private:

public:
	Span();
	Span(unsigned int size);
	Span(Span const & copy);
	Span & operator=(Span const &assign);
	~Span();
	void addNumber(int number);
	void addNumber();
	shortestSpan() const;
	longestSpan() const;
};

#endif