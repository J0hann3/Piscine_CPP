/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:38:39 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 19:14:59 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
float	get_area(Point const & a, Point const & b, Point const & c)
{
	float a1 = (b.getX() - a.getX()).toFloat();
	float a3 = (b.getY() - a.getY()).toFloat();
	float a4 = (c.getX() - a.getX()).toFloat();
	float a2 = (c.getY() - a.getY()).toFloat();
	float res = (a1 * a2) - (a3 * a4);
	if (res < 0)
		res = -res;
	res = res / 2.0;
	return res;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float a1 = get_area(a, b, c);
	float a2 = get_area(point, a, b);
	float a3 = get_area(point, a, c);
	float a4 = get_area(point, b, c);

	if (a2 == 0 || a3 == 0 || a4 == 0)
		return false;
	return (a1 == (a2 + a3 + a4));
}