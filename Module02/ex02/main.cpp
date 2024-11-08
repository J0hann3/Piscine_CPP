/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:37:54 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:23:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a2;
	Fixed const b2( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const b3( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const b4( Fixed( 5.05f ) - Fixed( 10 ) );
	Fixed const b5( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << "5.05 * 2 = " << b2 << std::endl;
	std::cout << "5.05 + 2 = " << b3 << std::endl;
	std::cout << "5.05 - 10 = " << b4 << std::endl;
	std::cout << "5.05 / 2 = " << b5 << std::endl;

	std::cout << a2 << std::endl;
	std::cout << ++a2 << std::endl;
	std::cout << a2 << std::endl;
	std::cout << a2++ << std::endl;
	std::cout << a2 << std::endl;


	std::cout << "Max :" << Fixed::max( a2, b2 ) << std::endl;
	std::cout << "Min :" << Fixed::min( a2, b2 ) << std::endl;
	
	return 0;
}