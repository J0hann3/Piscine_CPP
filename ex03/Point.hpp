/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:32:42 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:25:11 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private :
	Fixed const _x;
	Fixed const _y;

public :
	Point();
	Point(float const a, float const b);
	Point(Point const & point);
	Point & operator=(Point const & point);
	~Point();
	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif