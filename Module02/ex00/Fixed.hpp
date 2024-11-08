/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:29:40 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/18 16:08:01 by jvigny           ###   ########.fr       */
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

	Fixed(void);
	Fixed(Fixed const & fix);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed & operator=(Fixed const & fixed);
};

#endif