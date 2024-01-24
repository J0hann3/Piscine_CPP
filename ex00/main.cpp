/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:57:39 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/22 16:35:30 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
	std::cout << "--- Vector ---" << std::endl;
	std::vector<int> tab(10, 13);
	easyfind(tab, 7);
	easyfind(tab, 13);

	std::cout << "--- Deque ---" << std::endl;
	std::deque<int> queue(tab.begin(), tab.end());
	easyfind(queue, 13);
	easyfind(queue, 7);

	std::cout << "--- List ---" << std::endl;
	std::list<int> lst(0, 5);
	easyfind(lst, 13);
	easyfind(lst, 5);
	std::list<int> lst1(5, 15);
	easyfind(lst1, 13);
	easyfind(lst1, 15);
}