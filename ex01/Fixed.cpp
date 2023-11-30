/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:40:14 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/30 19:45:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fraction_bits = 8;

Fixed::Fixed(void): _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = number << Fixed::_fraction_bits;
}

Fixed::Fixed(float const number)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = number * std::pow(2,Fixed::_fraction_bits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}

Fixed & Fixed::operator=(Fixed const & fixed)
{
	std::cout << "Copy assignment operator called" <<std::endl;
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
