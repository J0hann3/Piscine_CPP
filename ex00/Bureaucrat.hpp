/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:48:08 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/10 18:59:09 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
private :
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const name);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const & bureaucrat);
	Bureaucrat & operator=(Bureaucrat const & bureaucrat);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	class TooHighException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Bureaucrat::GradeTooHighException";
		}
	};
	class TooLowException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Bureaucrat::GradeTooLowException";
		}
	};
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const & bureaucrat);


#endif
