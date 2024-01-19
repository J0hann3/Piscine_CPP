/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:45:05 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/19 19:52:39 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T& container, int value)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		std::cout << "Element find" << std::endl;
	else
		std::cout << "No element find" << std::endl;
}

#endif