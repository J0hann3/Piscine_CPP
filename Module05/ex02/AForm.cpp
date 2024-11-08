/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:26 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/15 14:42:35 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

const char* AForm::TooHighException::what() const throw()
{
	return "AForm::GradeTooHighException";
}

const char* AForm::TooLowException::what() const throw()
{
	return "AForm::GradeTooLowException";
}

const char* AForm::NotsignedException::what() const throw()
{
	return "AForm::NotsignedException";
}

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign < 1)
		throw AForm::TooHighException();
	else if (gradeSign > 150)
		throw AForm::TooLowException();
	if (gradeExecute < 1)
		throw AForm::TooHighException();
	else if (gradeExecute > 150)
		throw AForm::TooLowException();
}


AForm::AForm(AForm const & form) : _name(form._name), _isSigned(form._isSigned), _gradeSign(form._gradeSign), _gradeExecute(form._gradeExecute)
{}

AForm & AForm::operator=(AForm const & form)
{
	std::cout << "Assignement operator can only assign the signature to the new form" <<std::endl;
	_isSigned = form._isSigned;
	return (*this);
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExecute() const
{
	return _gradeExecute;
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (_isSigned == true)
	{
		std::cout << "Form is already sign" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= _gradeSign)
	{
		_isSigned = true;
		std::cout << "AForm signed !" << std::endl;
	}
	else
		throw AForm::TooLowException();
}

std::ostream & operator<<(std::ostream &o, AForm const & form)
{
	o << form.getName() << ", form is ";
	if (form.getIsSigned() == true)
		o << "signed";
	else
		o << "not signed";
	o << ". The require grade to signed is " << form.getGradeSign();
	o << ". The require grade to execute is " << form.getGradeExecute() << std::endl;
	return o;
}