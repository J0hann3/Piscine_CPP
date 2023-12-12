/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:32:42 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 20:03:52 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(float const a, float const b): _x(a), _y(b)
{}

Point::Point(Point const & point): _x(point._x), _y(point._y)
{}

Point & Point::operator=(Point const & point)
{
	std::cout << "ATTENTION, impossible to change the value, because _x and _y are const" <<std::endl;
	return *this;
}

Point::~Point()
{}

Fixed Point::getX(void) const
{
	return _x;
}

Fixed Point::getY(void) const
{
	return _y;
}

