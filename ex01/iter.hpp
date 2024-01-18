/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:03:12 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/18 13:59:49 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *tab, int length, void (*f)(T &))
{
	if (tab == 0 || f == 0)
		return ;
	for (int i = 0; i < length; i++)
	{
		f(tab[i]);
	}
}

template<typename T>
void addFloat(T &nb)
{
	nb++;
}


#endif