/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:14:54 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/16 19:01:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

Base * generate(void)
{
	int random = rand();
	if (random % 3 == 0)
	{
		std::cout << "Object of type A created" << std::endl;
		return (new A);
	}
	else if (random % 3 == 1)
	{
		std::cout << "Object of type B created" << std::endl;
		return (new B);
	}
	std::cout << "Object of type C created" << std::endl;
	return (new C);
}

void identify(Base* p)
{
	A *tmp = dynamic_cast<A *>(p);
	if (tmp != NULL)
	{
		std::cout << "The object is of type A" << std::endl;
		return ;
	}
	B *tmp1 = dynamic_cast<B *>(p);
	if (tmp1 != NULL)
	{
		std::cout << "The object is of type B" << std::endl;
		return ;
	}
	C *tmp2 = dynamic_cast<C *>(p);
	if (tmp2 != NULL)
	{
		std::cout << "The object is of type C" << std::endl;
		return ;
	}
	std::cout << "Unknown object" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &tmp = dynamic_cast<A &>(p); (void)tmp;
		std::cout << "The object is of type A" << std::endl;
		return ;
	}
	catch(std::exception& e){}
	try
	{
		B &tmp = dynamic_cast<B &>(p); (void)tmp;
		std::cout << "The object is of type B" << std::endl;
		return ;
	}
	catch(std::exception& e){}
	try
	{
		C &tmp = dynamic_cast<C &>(p); (void)tmp;
		std::cout << "The object is of type C" << std::endl;
		return ;
	}
	catch(std::exception& e){}
	std::cout << "Unknown object" << std::endl;
}