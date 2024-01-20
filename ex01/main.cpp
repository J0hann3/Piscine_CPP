/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:59:58 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/20 19:18:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try {
		std::vector<int> tmp(24, 12);
		Span test = Span(25);
		test.addNumber(tmp.begin(), tmp.end());
		test.addNumber(6);
		test.print();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int> tmp(10000, 0);
	Span test = Span(10000);
	test.addNumber(tmp.begin(), tmp.end());
	test.print();

	return 0;
}