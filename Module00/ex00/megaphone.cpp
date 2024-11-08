/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:23:26 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/30 16:16:39 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc <=  1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str (argv[i]);
			for (size_t j = 0; j < str.size(); j++)
				str.at(j) = std::toupper(str.at(j));
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
