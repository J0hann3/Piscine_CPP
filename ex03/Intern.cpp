/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:34:23 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 15:03:35 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(Intern const & intern)
{
	*this = intern;
}

Intern & Intern::operator=(Intern const & intern)
{
	(void) intern;
	return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
	AForm *tab[] = {new ShrubberyCreationForm(targetForm),
					new PresidentialPardonForm(targetForm),
					new RobotomyRequestForm(targetForm)};
	std::string names[] = {"shrubbery creation",
							"presidential pardon",
							"robotomy request"};
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i].compare(formName) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			for (int j = 0; j < 3; j++)
				if (j != i)
					delete tab[j];
			return tab[i];
		}
	}
	std::cout << "Form pass in argument doesn't correspond to any Form Classes" << std::endl;
	for (int i = 0; i < 3; i++)
		delete tab[i];
	return(NULL);
}
