/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:16:39 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 15:20:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a;
	Point b(1, 6.3);
	Point c(75, 63.2);
	Point cBis(c);
	Point d(13.17, 13.87);
	Point e(23.97, 68.46);

	if (bsp(a, b, c, d) == true)
		std::cout << "The point is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point is OUSIDE the triangle" << std::endl;

	if (bsp(a, b, c, cBis) == true)
		std::cout << "The point is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point is OUSIDE the triangle" << std::endl;

	if (bsp(c, a, b, d) == true)
		std::cout << "The point is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point is OUSIDE the triangle" << std::endl;

	if (bsp(a, b, c, e) == true)
		std::cout << "The point is INSIDE the triangle" << std::endl;
	else
		std::cout << "The point is OUSIDE the triangle" << std::endl;
}