/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:45:05 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/19 19:26:38 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>

template<typename T>
void easyfind(T& container, int value)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
		{
			std::cout << "Find" << std::endl;
			return;
		}
	}
	std::cout << "Not Find" << std::endl;
	return;
}

#endif