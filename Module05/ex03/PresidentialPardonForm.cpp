/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:58:33 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 14:25:11 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & form) : AForm(form), _target(form._target)
{

	if (_gradeSign < 1)
		throw PresidentialPardonForm::TooHighException();
	else if (_gradeSign > 150)
		throw PresidentialPardonForm::TooLowException();
	if (_gradeExecute < 1)
		throw PresidentialPardonForm::TooHighException();
	else if (_gradeExecute > 150)
		throw PresidentialPardonForm::TooLowException();
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & form)
{
	AForm::operator=(form);
	_target = form._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (_isSigned == false)
		throw AForm::NotsignedException();
	else if (executor.getGrade() > _gradeExecute)
		throw AForm::TooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
