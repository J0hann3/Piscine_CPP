/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:43:35 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/18 12:57:45 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T>
void swap(T & a, T & b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template< typename T>
T const & min(T const & a, T const & b)
{
	return ((a < b) ? a : b);
}

template< typename T>
T const & max(T const & a, T const & b)
{
	return ((a > b) ? a : b);
}

#endif