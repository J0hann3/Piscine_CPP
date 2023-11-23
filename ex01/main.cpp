/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:04:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/23 20:13:47 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void	PhoneBook::add_contact(void)
{
	Contact	new_contact;
	std::string	input;
	
	std::cout << "Enter First name :" << std::endl;
	std::cin >> new_contact.FirstName;
	if (new_contact.FirstName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return ;
	}
		
	std::cout << "Enter Last name :" << std::endl;
	std::cin >> new_contact.LastName;
	if (new_contact.LastName.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return ;
	}
		
	std::cout << "Enter Nickname :" << std::endl;
	std::cin >> new_contact.Nickname;
	if (new_contact.Nickname.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return ;
	}
		
	std::cout << "Enter Phone number :" << std::endl;
	std::cin >> new_contact.PhoneNumber;
	if (new_contact.PhoneNumber.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return ;
	}
		
	std::cout << "Enter Darkest Secret :" << std::endl;
	std::cin >> new_contact.DarkestSecret;
	if (new_contact.DarkestSecret.empty() == true)
	{
		std::cout << "Error : you can't have empty fields" << std::endl;
		return ;
	}
		
	//set_time
	//add contact
}

int main()
{
	PhoneBook book;
	std::string	input;

	while (1)
	{
		std::cout << "You can ADD a contact, SEARCH a contact or EXIT the phonebook" << std::endl;
		std::cin >> input;
		if (input.empty() == true)
			continue ;
		else if (input.compare("ADD") == 0)
		{
			std::cout << "ADD item" << std::endl;
			book.add_contact();
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH item" << std::endl;
		}
		else if (input.compare("EXIT") == 0)
			return 0;
	}
}