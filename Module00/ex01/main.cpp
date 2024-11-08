/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:04:52 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/10 18:26:54 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void get_line_stdin(std::string& line);

int	main()
{
	PhoneBook book;
	std::string	input;

	while (!std::cin.fail())
	{
		input.clear();
		std::cout << "You can ADD a contact, SEARCH a contact or EXIT the phonebook" << std::endl;
		get_line_stdin(input);
		if (input.compare("ADD") == 0)
			book.add_contact();
		else if (input.compare("SEARCH") == 0)
			book.search_contact();
		else if (input.compare("EXIT") == 0)
			return 0;
	}
	return 0;
}