/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:50:51 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/08 13:37:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <ctime>

class Contact
{
private :
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
	std::time_t	_time;
	int			_is_use;

public :

	Contact(void);
	bool is_empty(void) const;
	std::time_t get_time(void) const;
	bool create_contact(void);
	void print_contact_list(int index) const;
	void print_contact_info() const;
};

#endif