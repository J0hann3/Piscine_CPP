/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:30:06 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/10 19:07:53 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat first;
	Bureaucrat second("Second");
	Bureaucrat third(first);

	try
	{
		Bureaucrat five("five", -1);
		std::cout << five;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat six("six", 151);
		std::cout << six;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat forth("Forth", 5);
		std::cout << forth;
		for (int i = 0; i < 5; i++)
			forth.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat test("Test", 140);
		std::cout << test;
		for (int i = 0; i < 150; i++)
			test.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}