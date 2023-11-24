/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:56 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/24 17:28:58 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	std::cout <<oldest_index;
	this->contacts[oldest_index] = new_contact;
}


void	PhoneBook::search_contact(void)
{
	int input;

	for (int i = 0; i < 8 ; i++)
	{
		if (!this->contacts[i].is_empty())
			this->contacts[i].print_contact_list(i);
	}
	std::cout << "Enter the index of the contact you want :" << std::endl;
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cout << "Error : phonebook" <<input<< std::endl;
		std::cin.clear();
		std::cout <<std::cin.good() << std::endl;
		return ;
	}
	else if (input < 0 || input >= 8 || this->contacts[input].is_empty())
	{
		std::cout << "Error : invalid index to search the phonebook" << std::endl;
		return ;
	}
	this->contacts[input].print_contact_info();
}
