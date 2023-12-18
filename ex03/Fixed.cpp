/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:40:14 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:30:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fraction_bits = 8;

Fixed::Fixed(void): _fixed_point(0)
{
}

Fixed::Fixed(Fixed const & fix)
{
	_fixed_point = 	fix._fixed_point;
}

Fixed::Fixed(int const number)
{
	_fixed_point = number << Fixed::_fraction_bits;
}

Fixed::Fixed(float const number)
{
	_fixed_point = roundf(number * (1 << Fixed::_fraction_bits));
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits( void ) const
{
	return _fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	_fixed_point = raw;
}

Fixed & Fixed::operator=(Fixed const & fixed)
{
	_fixed_point = fixed.getRawBits();
	return *this;
}

float Fixed::toFloat( void ) const
{
	return _fixed_point / std::pow(2,Fixed::_fraction_bits);
}

int Fixed::toInt( void ) const
{
	return _fixed_point >> Fixed::_fraction_bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & number)
{
	o << number.toFloat();
	return o;
}

bool Fixed::operator>(Fixed const & fixed) const
{
	return (_fixed_point > fixed._fixed_point);
}

bool Fixed::operator<(Fixed const & fixed) const
{
	return (_fixed_point < fixed._fixed_point);
}

bool Fixed::operator>=(Fixed const & fixed) const
{
	return (_fixed_point >= fixed._fixed_point);
}

bool Fixed::operator<=(Fixed const & fixed) const
{
	return (_fixed_point <= fixed._fixed_point);
}

bool Fixed::operator==(Fixed const & fixed) const
{
	return (_fixed_point == fixed._fixed_point);
}

bool Fixed::operator!=(Fixed const & fixed) const
{
	return (_fixed_point != fixed._fixed_point);
}

Fixed Fixed::operator+(Fixed const & fixed) const
{
	Fixed res;
	res._fixed_point = (_fixed_point + fixed._fixed_point);
	return res;
}

Fixed Fixed::operator-(Fixed const & fixed) const
{
	Fixed res;
	res._fixed_point = (_fixed_point - fixed._fixed_point);
	return res;
}

Fixed Fixed::operator*(Fixed const & fixed) const
{
	Fixed res;
	res._fixed_point = ((int64_t)_fixed_point * (int64_t)fixed._fixed_point) >> Fixed::_fraction_bits;
	return res;
}

Fixed Fixed::operator/(Fixed const & fixed) const
{
	Fixed res;
	res._fixed_point = ((int64_t)_fixed_point << Fixed::_fraction_bits) / fixed._fixed_point;
	return res;
}

Fixed& Fixed::operator++()
{
	_fixed_point++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	_fixed_point--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);
	_fixed_point++;
	return (res);
}

Fixed Fixed::operator--(int)
{
	Fixed res(*this);
	_fixed_point--;
	return (res);
}

Fixed& Fixed::min(Fixed& fix1, Fixed& fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed const & Fixed::min(Fixed const & fix1, Fixed const & fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed& Fixed::max(Fixed& fix1, Fixed & fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

Fixed const & Fixed::max(Fixed const & fix1, Fixed const & fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}
