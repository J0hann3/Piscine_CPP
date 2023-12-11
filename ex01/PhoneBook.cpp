/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:56 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/11 13:28:03 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
void get_line_stdin(std::string& line);

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the Phonebook!" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "See you soon!" << std::endl;
}

void	PhoneBook::add_contact(void)
{
	Contact		new_contact;
	std::time_t	oldest_time;
	int			oldest_index;
	
	if (new_contact.create_contact() == false)
		return ;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].is_empty())
		{
			this->contacts[i] = new_contact;
			return ;
		}
	}
	oldest_time = this->contacts[0].get_time();
	oldest_index = 0;
	for (int i = 1; i < 8; i++)
	{
		if (this->contacts[i].get_time() < oldest_time)
		{
			oldest_index = i;
			oldest_time = this->contacts[i].get_time();
		}
	}
	this->contacts[oldest_index] = new_contact;
}


void	PhoneBook::search_contact(void)
{
	std::string input;

	for (int i = 0; i < 8 ; i++)
	{
		if (!this->contacts[i].is_empty())
			this->contacts[i].print_contact_list(i);
	}
	std::cout << "Enter the index of the contact you want :" << std::endl;
	get_line_stdin(input);
	if (input.size() > 1 || input[0] < '0' || input[0] >= '8' || this->contacts[input[0] - '0'].is_empty())
	{
		std::cout << "Error : invalid index to search the phonebook" << std::endl;
		return ;
	}
	this->contacts[input[0] - '0'].print_contact_info();
}
