/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:45:22 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/16 18:47:46 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data Arthur = {"Arthur", 20, "Volley_ball"};
	std::cout << &Arthur << std::endl;

	
	uintptr_t tmp = Serialization::serialize(&Arthur);
	std::cout << tmp << std::endl;
	Data *res = Serialization::deserialize(tmp);
	std::cout << res << std::endl;
	std::cout << "Name :" << res->_name << std::endl;
	std::cout << "Age :" << res->_age << std::endl;
	std::cout << "Passion :" << res->_passion << std::endl;
	return 0;
}