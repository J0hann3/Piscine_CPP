/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:47:46 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/23 20:10:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{

public :

	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;

	// Contact(void);
	// ~Contact(void);
};

class PhoneBook {

public :

	Contact contacts[8];

	void	add_contact(void);
	void	search_contact(void);
	// PhoneBook(void);
	// ~PhoneBook(void);
};
#endif