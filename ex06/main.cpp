/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:59:20 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/28 15:44:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getNumber( std::string level )
{
	int i = 0;
	std::string name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
	{
		if (level.compare(name[i]) == 0)
			return i;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error : invalid number of argument" << std::endl;
		return 1;
	}
	int nb(getNumber(argv[1]));
	Harl harl;

	switch(nb)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0 :
			harl.complain("DEBUG");
		case 1 :
			harl.complain("INFO");
		case 2 :
			harl.complain("WARNING");
		case 3 :
			harl.complain("ERROR");
	}

	return 0;
}