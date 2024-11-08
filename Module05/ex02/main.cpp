/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:30:06 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 14:21:29 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	std::cout << "--- ShrubberyCreationForm ---" << std::endl;
	try 
	{
		Bureaucrat me("me", 100);
		ShrubberyCreationForm one("home");
		std::cout << one;
		me.signForm(one);
		std::cout << one;
		me.executeForm(one);
		std::cout << one << std::endl << std::endl;

		ShrubberyCreationForm two;
		std::cout << two;
		two.beSigned(me);
		std::cout << two;
		two.execute(me);
		std::cout << two << std::endl  << std::endl;
		ShrubberyCreationForm three("three");
		std::cout << three;
		three.execute(me);
		std::cout << three;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- PresidentialPardonForm ---" << std::endl << std::endl;

	try 
	{
		Bureaucrat me("me", 5);
		PresidentialPardonForm one("test");
		std::cout << one;
		me.signForm(one);
		std::cout << one;
		me.executeForm(one);
		std::cout << one << std::endl << std::endl;

		PresidentialPardonForm two;
		std::cout << two;
		two.beSigned(me);
		std::cout << two;
		two.execute(me);
		std::cout << two << std::endl  << std::endl;

		Bureaucrat test("me", 36);
		PresidentialPardonForm three(one);
		std::cout << three;
		three.execute(test);
		std::cout << three;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--- RobotomyRequestForm ---" << std::endl << std::endl;

	try 
	{
		Bureaucrat me("me", 1);
		RobotomyRequestForm one("coucou");
		std::cout << one;
		me.signForm(one);
		std::cout << one;
		me.executeForm(one);
		std::cout << one << std::endl << std::endl;

		RobotomyRequestForm two;
		std::cout << two;
		two.beSigned(me);
		std::cout << two;
		two.execute(me);
		std::cout << two << std::endl  << std::endl;

		Bureaucrat test("me", 150);
		RobotomyRequestForm three(one);
		std::cout << three;
		three.execute(test);
		std::cout << three;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}