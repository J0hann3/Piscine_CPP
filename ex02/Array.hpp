/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:06:28 by jvigny            #+#    #+#             */
/*   Updated: 2024/02/19 12:41:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
public:
	Array() : _array(NULL), _size(0){}
	Array(unsigned int n) : _size(n)
	{
		_array = new T[n];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = 0;
	}
	Array(Array const & copy)
	{
		if (copy._array == NULL)
		{
			_size = 0;
			_array = NULL;
			return ;
		}
		_array = new T[copy._size];
		_size = copy._size;
		for (unsigned int i = 0; i < copy._size; i++)
		{
			_array[i] = copy._array[i];
		}
	}
	Array & operator=(Array const & copy)
	{
		if (&copy == this)
			return *this;
		if (_size != 0)
			delete [] _array;
		if (copy._array == NULL)
		{
			_size = 0;
			_array = NULL;
			return *this;
		}
		_array = new T[copy._size];
		_size = copy._size;
		for (unsigned int i = 0; i < copy._size; i++)
		{
			_array[i] = copy._array[i];
		}
		return *this;
	}
	~Array()
	{
		if (_size != 0)
			delete [] _array;
	}
	T & operator[](unsigned int index)
	{
		if (index >= _size || index < 0 || _array == NULL)
			throw std::out_of_range("Try to access out of the array");
		return (_array[index]);
	}
	T const & operator[](unsigned int index) const
	{
		if (index >= _size || index < 0 || _array == NULL)
			throw std::out_of_range("Try to access out of the array");
		return (_array[index]);
	}
	unsigned int size() const
	{
		return _size;
	}
};


#endif