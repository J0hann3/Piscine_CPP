/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:23:26 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/23 18:38:29 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

char ft_toupper(char c)
{
	return toupper(c);
}

int main(int argc, char *argv[])
{
	if (argc <=  1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str (argv[i]);
			std::transform(str.begin(), str.end(), str.begin(), ft_toupper);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
