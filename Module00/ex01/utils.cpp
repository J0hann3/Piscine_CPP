/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:47 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/08 14:04:44 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

void get_line_stdin(std::string& line)
{
	while (1)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cin.clear(std::cin.goodbit);
			std::clearerr(stdin);
		}
		else
			return ;
	}

}