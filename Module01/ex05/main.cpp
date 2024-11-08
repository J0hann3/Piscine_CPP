/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:26:25 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 18:06:00 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl test;

	test.complain("DEBUG");
	test.complain("jdfkl");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("ERROR");
	return 0;
}