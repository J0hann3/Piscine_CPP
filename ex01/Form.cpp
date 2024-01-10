/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:33:21 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/10 20:34:17 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Default"), _isSigned(false), _gradeExecute(150), _gradeSign(150)
{}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeExecute(gradeExecute), _gradeSign(gradeSign)
{
	if (gradeExecute < 1)
		throw Form::TooHighException();
	else if (gradeExecute > 150)
		throw Form::TooLowException();
	if (gradeSign < 1)
		throw Form::TooHighException();
	else if (gradeSign > 150)
		throw Form::TooLowException();
}


Form::Form(Form const & form) : _name(form._name), _isSigned(form._isSigned), _gradeExecute(form._gradeExecute), _gradeSign(form._gradeSign)
{}

Form & Form::operator=(Form const & form)
{
	std::cout << "Assignement operator can only assign the signature to the new form" <<std::endl;
	_isSigned = form._isSigned;
	return (*this);
}

Form::~Form()
{}

std::string Form::getName() const
{
	return _name;
}

int Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExecute() const
{
	return _gradeExecute;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw Form::TooLowException();
	bureaucrat.signForm(*this);
}

const char* Form::TooHighException::what() const throw()
{
	return "Form::GradeTooHighException";
}

const char* Form::TooLowException::what() const throw()
{
	return "Form::GradeTooLowException";
}

std::ostream & operator<<(std::ostream &o, Form const & form)
{
	o << form.getName() << ",form is ";
	if (form.getIsSigned() == true)
		o << "signed";
	else
		o << "not signed";
	o << ". The require grade to signed is " << form.getGradeSign();
	o << ". The require grade to execute is " << form.getGradeExecute() << std::endl;
	return o;
}