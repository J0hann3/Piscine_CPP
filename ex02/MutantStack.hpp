/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:20:12 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/12 12:07:28 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <class T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack(): std::stack<T, Container>(){}
	MutantStack(MutantStack const & copy): std::stack<T, Container>(copy){}
	MutantStack & operator=(MutantStack const & assign){
		std::stack<T, Container>::operator=(assign);
		return *this;
	}
	~MutantStack(){}

	typedef typename Container::iterator iterator;
	
	iterator begin() { return std::stack<T, Container>::c.begin(); }
	iterator end() { return std::stack<T, Container>::c.end(); }

	// * Create an iterator for the stack
	// ! Doesn't work because stack isn't stored continuously
	// class iterator {
	// private:
	// 	T* _ptr;
	// public:
	// 	iterator(): _ptr(NULL){}
	// 	iterator(T* ptr): _ptr(ptr){}
	// 	iterator(iterator const & copy): _ptr(copy._ptr){}
	// 	iterator & operator=(iterator const & assign){
	// 		_ptr = assign._ptr;
	// 		return *this;
	// 	}
	// 	~iterator(){}
	// 	iterator& operator++(){
	// 		_ptr++;
	// 		return *this;
	// 	}
	// 	iterator& operator++(int){
	// 		iterator &tmp = *this;
	// 		_ptr++;
	// 		return tmp;
	// 	}
	// 	iterator& operator--(){
	// 		_ptr--;
	// 		return *this;
	// 	}
	// 	iterator& operator--(int){
	// 		iterator &tmp = *this;
	// 		_ptr--;
	// 		return tmp;
	// 	}
	// 	T* operator->(){
	// 		return _ptr;
	// 	}
	// 	T& operator*(){
	// 		if (_ptr != NULL)
	// 			return *_ptr;
	// 		throw std::exception();
	// 	}
	// 	bool operator==(const iterator & other) const{
	// 		return (_ptr == other._ptr);
	// 	}
	// 	bool operator!=(const iterator & other) const{
	// 		return (_ptr != other._ptr);
	// 	} 
	// };
	// iterator begin(){
	// 	if (this->size() == 0)
	// 		return iterator();
	// 	return iterator((&this->top()) - this->size() + 1);
	// }
	// iterator end(){
	// 	if (this->size() == 0)
	// 		return iterator();
	// 	return iterator((&this->top()) + 1);
	// }
};

#endif