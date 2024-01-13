/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:28:45 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 14:57:11 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include <string>

class Intern
{
public:
	Intern();
	Intern(Intern const & intern);
	Intern & operator=(Intern const & intern);
	~Intern();
	AForm *makeForm(std::string formName, std::string targetForm);
};

#endif