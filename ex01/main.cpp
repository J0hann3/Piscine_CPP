/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:08 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:34:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define NUMBER 10

int main()
{
	Animal	*horde[NUMBER];

	for (int i = 0; i < NUMBER / 2; i++)
		horde[i] = new Dog();
	for (int i = NUMBER / 2; i < NUMBER; i++)
		horde[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < NUMBER; i++)
		horde[i]->makeSound();

	std::cout << std::endl;
	for (int i = 0; i < NUMBER; i++)
		delete horde[i];
	return 0;
}