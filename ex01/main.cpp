/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:09:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/18 14:03:21 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void print(int &nb)
{
	std::cout << nb << std::endl;
}

void change(char &c)
{
	c = toupper(c);
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	::iter(tab, 9, &print);
	std::cout << std::endl;


	char array[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	::iter(array, sizeof(array) / sizeof(char), change);
	for (unsigned int i = 0; i < sizeof(array) / sizeof(char); i++)
		std::cout << array[i] << std::endl;
	std::cout << std::endl;


	float array1[] = {1.1, 1.2, 1.3, 1.4, 1.5};
	
	::iter(array1, sizeof(array1) / sizeof(float), addFloat);
	for (unsigned int i = 0; i < sizeof(array1) / sizeof(float); i++)
		std::cout << array1[i] << std::endl;
}