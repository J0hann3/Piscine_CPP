/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:41:26 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/13 13:46:33 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error : Need number to merge-insert sort" << std::endl;
		return 1;
	}
	PmergeMe test;
	try
	{
		test.merge(argc, argv);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}