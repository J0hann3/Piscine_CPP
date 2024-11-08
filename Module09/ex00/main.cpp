/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:33:23 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/24 18:08:56 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid argument." <<std::endl;
		return 1;
	}
	std::map<std::string, float> map;
	if (!openData(map))
		return 1;
	if (!openInput(argv[1], map))
		return 1;
	return 0;
}