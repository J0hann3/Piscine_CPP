/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:47:46 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/25 16:57:14 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

#include "Contact.hpp"

class PhoneBook {

public :

	Contact contacts[8];

	void	add_contact(void);
	void	search_contact(void);
	PhoneBook(void);
	~PhoneBook(void);
};
#endif