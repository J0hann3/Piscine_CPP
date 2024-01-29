/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:38:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/29 13:27:38 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <climits>
# include <iostream>
# include <stdexcept>
# include <algorithm>

class PmergeMe
{
private:
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deque;
public:
	PmergeMe();
	PmergeMe & operator=(PmergeMe const & assign);
	PmergeMe(PmergeMe const & copy);
	~PmergeMe();
	
	void merge(int argc, char **argv);
	
	void merge_insert_vector(int argc, char **argv);
	void merge_insert_deque(int argc, char **argv);
};

#endif