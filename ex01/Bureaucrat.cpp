/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:20:39 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/15 14:36:07 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

const char* Bureaucrat::TooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::TooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::TooHighException();
	else if (grade > 150)
		throw Bureaucrat::TooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade)
{}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & bureaucrat)
{
	std::cout << "Assignement operator can only assign the grade to the new bureaucrat" <<std::endl;
	_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::TooHighException();
	else
	{
		_grade--;
		std::cout << "Increment the grade, new grade is " << _grade << std::endl;
	}
}

void Bureaucrat::decrement()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::TooLowException();
	else
	{
		_grade++;
		std::cout << "Decrement the grade, new grade is " << _grade  << std::endl;
	}
}

void Bureaucrat::signForm(Form & form) const
{
	if (form.getIsSigned() == true)
		std::cout << "The form is already signed" << std::endl;
	else if (form.getGradeSign() >= _grade)
	{
		std::cout << _name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because the grade is to low." << std::endl;
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const & bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." <<  std::endl;
	return o;
}
