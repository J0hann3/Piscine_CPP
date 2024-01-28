/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:38:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/28 18:08:38 by jvigny           ###   ########.fr       */
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
public:
	PmergeMe();
	PmergeMe(PmergeMe const & copy);
	PmergeMe & operator=(PmergeMe const & assign);
	~PmergeMe();

	void fill_vector_container(int argc, char **argv);
	void fill_list_container(int argc, char **argv);
	void merge_insert_vector(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);
	void merge_insert_vector2();
	void merge_insert_list(std::list<unsigned int>::iterator start, std::list<unsigned int>::iterator end);
	void merge(int argc, char **argv);
};

#endif