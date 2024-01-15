/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:34:52 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/15 14:49:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class AForm
{
protected:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
public:
	AForm();
	AForm(std::string name, int gardeSign, int gradeExecute);
	AForm(AForm const & form);
	AForm & operator=(AForm const & form);
	virtual ~AForm();
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(Bureaucrat const & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	class TooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class TooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class NotsignedException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, AForm const & form);

#endif