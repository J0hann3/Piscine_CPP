/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:30:06 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 15:02:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	try 
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf == NULL)
			return 0;
		std::cout << *rrf;
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf == NULL)
			return 0;
		std::cout << *rrf;
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf == NULL)
			return 0;
		std::cout << *rrf;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}