/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:47:10 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/14 16:04:44 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"


int main()
{
	srand(std::time(0));
	Base *test;

	for (int i = 0; i < 10; i++)
	{
		test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
	Base *coucou = new Base;
	identify(coucou);
	identify(*coucou);
	delete coucou;
}
