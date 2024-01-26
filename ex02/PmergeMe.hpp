/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:38:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/26 17:50:29 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <list>
# include <climits>
# include <iostream>
# include <stdexcept>
# include <algorithm>

class PmergeMe
{
private:
	std::vector<unsigned int> _vector;
	std::list<unsigned int> _list;
	std::vector<std::vector<unsigned int>::iterator> _resV;
	// std::list<unsigned int> _resL;
public:
	PmergeMe();
	PmergeMe(PmergeMe const & copy);
	PmergeMe & operator=(PmergeMe const & assign);
	~PmergeMe();

	unsigned int getSizeVector() const;
	void fill_vector_container(int argc, char **argv);
	void fill_list_container(int argc, char **argv);
	void merge_insert_vector(unsigned int iter);
	void merge_insert_list();
	void print() const;
	void printresV() const;
};

#endif