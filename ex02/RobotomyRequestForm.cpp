/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:52 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 14:11:03 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequest", 72, 45), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & form) : AForm(form), _target(form._target)
{

	if (_gradeSign < 1)
		throw RobotomyRequestForm::TooHighException();
	else if (_gradeSign > 150)
		throw RobotomyRequestForm::TooLowException();
	if (_gradeExecute < 1)
		throw RobotomyRequestForm::TooHighException();
	else if (_gradeExecute > 150)
		throw RobotomyRequestForm::TooLowException();
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & form)
{
	AForm::operator=(form);
	_target = form._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (_isSigned == false)
		throw AForm::NotsignedException();
	else if (executor.getGrade() > _gradeExecute)
		throw AForm::TooLowException();
	std::cout << "RobotomyRequestForm execute !" << std::endl;
	std::cout << "Drilling sound : Bzzzzzz" << std::endl;

	int random = rand();

	if (random % 2 == 0)
		std::cout << _name << " has been robotomized successfully" << std::endl;
	else
		std::cout << _name << " failed to be robotomize" << std::endl;
}