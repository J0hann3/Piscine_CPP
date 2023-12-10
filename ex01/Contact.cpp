/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:19 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/08 14:06:45 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
void get_line_stdin(std::string& line);

Contact::Contact(void)
{
	this->_time = std::time(NULL);
	this->_is_use = false;
	this->_FirstName.clear();
	this->_LastName.clear();
	this->_Nickname.clear();
	this->_PhoneNumber.clear();
	this->_DarkestSecret.clear();
}

bool Contact::create_contact(void)
{
	this->_time = std::time(NULL);
	this->_is_use = true;
	std::cout << "Enter First name :" << std::endl;
	get_line_stdin(this->_FirstName);
	if (this->_FirstName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Last name :" << std::endl;
	get_line_stdin(this->_LastName);
	if (this->_LastName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Nickname :" << std::endl;
	get_line_stdin(this->_Nickname);
	if (this->_Nickname.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Phone number :" << std::endl;
	get_line_stdin(this->_PhoneNumber);
	if (this->_PhoneNumber.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Darkest Secret :" << std::endl;
	get_line_stdin(this->_DarkestSecret);
	if (this->_DarkestSecret.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::is_empty(void) const
{
	return (!this->_is_use);
}

std::time_t	Contact::get_time(void) const
{
	return this->_time;
}

void	format_contact(std::string str)
{
	if (str.size() > 10)
	{
		char test[11];
		str.copy(test, 10, 0);
		test[9] = '.';
		std::cout << std::setfill(' ') << std::setw(10) << test;
	}
	else
		std::cout << std::setfill(' ') << std::setw(10) << str;
}

void	Contact::print_contact_list(int index) const
{
	std::cout << std::setfill(' ') << std::setw(10) << index;
	std::cout << '|';
	format_contact(this->_FirstName);
	std::cout << '|';
	format_contact(this->_LastName);
	std::cout << '|';
	format_contact(this->_Nickname);
	std::cout << std::endl;
}

void	Contact::print_contact_info(void) const
{
	std::cout << "First Name : " << this->_FirstName << std::endl;
	std::cout << "Last Name : " << this->_LastName << std::endl;
	std::cout << "Nickname : " << this->_Nickname << std::endl;
	std::cout << "Phone number : " << this->_PhoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->_DarkestSecret << std::endl;
}

