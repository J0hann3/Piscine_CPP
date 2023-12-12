/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:37:54 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/09 15:16:10 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	// Fixed a;
	// Fixed b( a );
	// Fixed c;

	// c = b;

	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	// Fixed a1;
	// Fixed const b1( 10 );
	// Fixed const c1( 42.42f );
	// Fixed const d1( b1 );

	// a1 = Fixed( 1234.4321f );

	// std::cout << "a1 is " << a1 << std::endl;
	// std::cout << "b1 is " << b1 << std::endl;
	// std::cout << "c1 is " << c1 << std::endl;
	// std::cout << "d1 is " << d1 << std::endl;
	
	// std::cout << "a1 is " << a1.toInt() << " as integer" << std::endl;
	// std::cout << "b1 is " << b1.toInt() << " as integer" << std::endl;
	// std::cout << "c1 is " << c1.toInt() << " as integer" << std::endl;
	// std::cout << "d1 is " << d1.toInt() << " as integer" << std::endl;

	Fixed a2;
	Fixed const b2( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a2 << std::endl;
	std::cout << ++a2 << std::endl;
	std::cout << a2 << std::endl;
	std::cout << a2++ << std::endl;
	std::cout << a2 << std::endl;

	std::cout << b2 << std::endl;

	std::cout << Fixed::max( a2, b2 ) << std::endl;
	
	return 0;
}