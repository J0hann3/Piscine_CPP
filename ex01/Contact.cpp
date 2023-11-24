/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:19 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/24 15:24:18 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void)
{
	this->time = std::time(NULL);
	this->is_use = false;
	this->FirstName.clear();
	this->LastName.clear();
	this->Nickname.clear();
	this->PhoneNumber.clear();
	this->DarkestSecret.clear();
}

bool Contact::create_contact(void)
{
	this->time = std::time(NULL);
	this->is_use = true;
	std::cout << "Enter First name :" << std::endl;
	std::cin >> this->FirstName;
	if (this->FirstName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Last name :" << std::endl;
	std::cin >> this->LastName;
	if (this->LastName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Nickname :" << std::endl;
	std::cin >> this->Nickname;
	if (this->Nickname.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Phone number :" << std::endl;
	std::cin >> this->PhoneNumber;
	if (this->PhoneNumber.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	std::cout << "Enter Darkest Secret :" << std::endl;
	std::cin >> this->DarkestSecret;
	if (this->DarkestSecret.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::is_empty(void) const
{
	return (!this->is_use);
}

std::time_t	Contact::get_time(void) const
{
	return this->time;
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
	format_contact(this->FirstName);
	std::cout << '|';
	format_contact(this->LastName);
	std::cout << '|';
	format_contact(this->Nickname);
	std::cout << std::endl;
}

void	Contact::print_contact_info(void) const
{
	std::cout << "First Name : " << this->FirstName << std::endl;
	std::cout << "Last Name : " << this->LastName << std::endl;
	std::cout << "Nickname : " << this->Nickname << std::endl;
	std::cout << "Phone number : " << this->PhoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->DarkestSecret << std::endl;
}

