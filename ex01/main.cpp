/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:04:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/28 12:59:43 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

int main()
{
	PhoneBook book;
	std::string	input;

	while (!(std::cin.eof() || std::cin.fail()))
	{
		input.clear();
		std::cout << "You can ADD a contact, SEARCH a contact or EXIT the phonebook" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			book.add_contact();
		else if (input.compare("SEARCH") == 0)
			book.search_contact();
		else if (input.compare("EXIT") == 0)
			return 0;
	}
	return 0;
}