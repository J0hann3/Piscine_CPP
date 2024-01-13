/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:48:32 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 13:33:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreation", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & form) : AForm(form), _target(form._target)
{

	if (_gradeSign < 1)
		throw ShrubberyCreationForm::TooHighException();
	else if (_gradeSign > 150)
		throw ShrubberyCreationForm::TooLowException();
	if (_gradeExecute < 1)
		throw ShrubberyCreationForm::TooHighException();
	else if (_gradeExecute > 150)
		throw ShrubberyCreationForm::TooLowException();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & form)
{
	AForm::operator=(form);
	_target = form._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (_isSigned == false)
		throw AForm::NotsignedException();
	else if (executor.getGrade() > _gradeExecute)
		throw AForm::TooLowException();
	std::cout << "ShrubberyCreationForm execute !" << std::endl;
	std::string filename = _name + "_shrubbery";
	std::ofstream file(filename.c_str(), std::ofstream::out);
	if (!file.is_open())
	{
		std::cout << "Error : Can't open file" <<std::endl;
		return ;
	}
	std::cout << "               ,@@@@@@@,"  << std::endl
			  << "       ,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl
			  << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"  << std::endl
			  << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"  << std::endl
			  << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"  << std::endl
			  << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"  << std::endl
			  << "   `&%\\ ` /%&'    |.|        \\ '|8'"  << std::endl
			  << "       |o|        | |         | |"  << std::endl
			  << "       |.|        | |         | |"  << std::endl
			  << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	file.close();
}