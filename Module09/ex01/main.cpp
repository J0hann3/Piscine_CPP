/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:23:10 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/25 14:17:51 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : invalid number of argument" << std::endl;
		return 1;
	}
	RPN stack;

	if (!stack.fill(argv[1]))
		return 1;
	stack.calculate();
	return 0;
}