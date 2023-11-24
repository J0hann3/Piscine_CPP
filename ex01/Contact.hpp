/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:50:51 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/24 15:21:06 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <ctime>

class Contact
{
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
	std::time_t	time;
	int			is_use;

public :

	Contact(void);
	bool is_empty(void) const;
	std::time_t get_time(void) const;
	bool create_contact(void);
	void print_contact_list(int index) const;
	void print_contact_info() const;
	// Contact(int c);
	// ~Contact(void);
};

#endif