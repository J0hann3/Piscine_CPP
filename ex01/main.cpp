/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:59:58 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/12 11:51:58 by jvigny           ###   ########.fr       */
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
	try
	{
		sp.addNumber(23);
		sp.print();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span : " << sp.longestSpan() << std::endl;

	try
	{
		Span test = Span(2);
		// test.addNumber(3);
		std::cout << "Shortest Span : " << test.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int> tmp(24, 12);
		Span test = Span(24);
		test.addNumber(tmp.begin(), tmp.end());
		test.addNumber(6);
		test.print();
		std::cout << "Shortest Span : " << test.shortestSpan() << std::endl;
		std::cout << "Longest Span : " <<test.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> tmp(10000, 0);
	Span test = Span(10000);
	test.addNumber(tmp.begin(), tmp.end());
	test.print();
	std::cout << "Shortest Span : " << test.shortestSpan() << std::endl;
	std::cout << "Longest Span : " <<test.longestSpan() << std::endl;

	return 0;
}