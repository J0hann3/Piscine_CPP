/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:29:40 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:27:17 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private :
	int _fixed_point;
	static const int _fraction_bits;
public :
	//Constructor
	Fixed(void);
	Fixed(Fixed const & fix);
	Fixed(int const number);
	Fixed(float const number);
	~Fixed(void);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed& min(Fixed& fix1, Fixed& fix2);
	static Fixed const & min(Fixed const & fix1, Fixed const & fix2);
	static Fixed& max(Fixed& fix1, Fixed & fix2);
	static Fixed const & max(Fixed const & fix1, Fixed const & fix2);
	
	//Overload operator
	Fixed & operator=(Fixed const & fixed);
	bool operator>(Fixed const & fixed) const;
	bool operator<(Fixed const & fixed) const;
	bool operator>=(Fixed const & fixed) const;
	bool operator<=(Fixed const & fixed) const;
	bool operator==(Fixed const & fixed) const;
	bool operator!=(Fixed const & fixed) const;
	Fixed operator+(Fixed const & fixed) const;
	Fixed operator-(Fixed const & fixed) const;
	Fixed operator*(Fixed const & fixed) const;
	Fixed operator/(Fixed const & fixed) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream & operator<<(std::ostream & o, Fixed const & number);

#endif