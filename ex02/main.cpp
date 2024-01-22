/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:10:04 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/22 13:07:47 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		Array<float>a;
		Array<float>b(20);

		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;
		std::cout << std::endl;
		
		for (unsigned int i = 0; i < b.size(); i++)
			b[i] = i + 0.5;
		a = b;
		b[0] = 23.23;
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << std::endl;
		b[-1];
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<int>d(20);
		for (unsigned int i = 0; i < d.size(); i++)
			d[i] = i + 50;
		std::cout <<std::endl;

		Array<int>c(d);
		d[3] = 0;
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << c[i] << std::endl;
		std::cout <<std::endl;
		for (unsigned int i = 0; i < d.size(); i++)
			std::cout << d[i] << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}