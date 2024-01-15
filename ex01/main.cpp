/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:30:06 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/15 14:41:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl << "--- Invalid Form creation ---" << std::endl << std::endl;
	try
	{
		Form first;
		std::cout << first;
		Form third(first);
		std::cout << third;
		Form five("five", -1, 20);
		std::cout << five;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form six("six", 20, 151);
		std::cout << six;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Invalid Signature Form ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat me("me", 5);
		std::cout << me;
		Form form("form", 1, 10);
		std::cout << form;
		form.beSigned(me);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat me("me", 5);
		std::cout << me;
		Form form("form", 1, 10);
		std::cout << form;
		me.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- Valid Signature Form ---" << std::endl << std::endl;
	try 
	{
		Bureaucrat forth("Forth", 5);
		std::cout << forth;
		Form form("form", 5, 10);
		std::cout << form;
		form.beSigned(forth);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		Bureaucrat coucou("coucou", 5);
		std::cout << coucou;
		Form form("form", 5, 10);
		std::cout << form;
		coucou.signForm(form);
		coucou.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}