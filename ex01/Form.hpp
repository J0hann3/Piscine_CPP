/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:18:54 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/10 19:58:32 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
public:
	Form();
	Form(std::string name, int gardeSign, int gradeExecute);
	Form(Form const & form);
	Form & operator=(Form const & form);
	~Form();
	std::string getName() const;
	int getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(Bureaucrat const & bureaucrat);
	class TooLowException
	{
		virtual const char* what() const throw();
	};
	class TooHighException
	{
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, Form const & form);

#endif