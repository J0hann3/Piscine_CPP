/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:22:51 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/12 12:11:40 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <algorithm>

int main()
{
	MutantStack<int> mstack;
	mstack.push(9);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> test(mstack);

	std::cout << "--- Copy ---" <<std::endl;
	MutantStack<int> s(mstack);

	mstack.pop();
	it = s.begin();
	ite = s.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
		it--;
		it++;
	}
	return 0;
}