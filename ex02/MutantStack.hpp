/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:20:12 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/20 19:45:44 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	MutantStack();
	MutantStack(MutantStack const & copy);
	MutantStack & operator=(MutantStack const & assign);
	~MutantStack();
	
	class Iterator {
	public:
		reference operator*() const;
		Iterator& operator++();
		Iterator& operator++(int);
		Iterator& operator--();
		Iterator& operator--(int);
		bool operator==();
		bool operator!=(); 
		Iterator begin();
		Iterator end();
	};


};

#endif