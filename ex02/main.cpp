/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:41:26 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/25 20:34:16 by jvigny           ###   ########.fr       */
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
	test.fill_vector_container(argc, argv);
	test.fill_list_container(argc, argv);
}