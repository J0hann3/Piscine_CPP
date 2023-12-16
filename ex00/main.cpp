/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:08 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 20:25:45 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	const WrongAnimal* test = new WrongAnimal();
	const WrongCat* cat = new WrongCat();
	const WrongAnimal* c = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << test->getType() << " " << std::endl;
	cat->makeSound();
	c->makeSound();
	test->makeSound();
	
	std::cout << std::endl;
	delete test;
	delete cat;
	delete c;
	return 0;
}