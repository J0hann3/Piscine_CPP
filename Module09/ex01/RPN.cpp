/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:29:04 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/25 14:53:32 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _input(std::stack<char>())
{}

RPN::RPN(RPN const & copy): _input(std::stack<char>(copy._input))
{}

RPN & RPN::operator=(RPN const & assign)
{
	_input = assign._input;
	return *this;
}

RPN::~RPN()
{}

bool RPN::fill(std::string str)
{
	std::string oper = "+-*/";

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (std::isdigit(str.at(i)) != 0)
		{
			_input.push(str.at(i));
			i--;
			if (i >= 0 && str.at(i) != ' ')
			{
				std::cout << "Error : mising space after digit" << std::endl;
				return false;
			}
		}
		else if (oper.find(str.at(i)) != std::string::npos)
		{
			_input.push(str.at(i));
			i--;
			if (i >= 0 && str.at(i) != ' ')
			{
				std::cout << "Error : mising space after operant" << std::endl;
				return false;
			}
		}
		else if (str.at(i) != ' ')
		{
			std::cout << "Error : Invalid character in the input" << std::endl;
			return false;
		}
	}
	return true;
}

bool RPN::calculate()
{
	std::stack<int> res;

	while (!_input.empty())
	{
		int elem = _input.top();
		_input.pop();
		if (std::isdigit(elem) != 0)
			res.push(elem - '0');
		else
		{
			if (res.size() < 2)
			{
				std::cout << "Error : Wrong input format" <<std::endl;
				return false;
			}
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			switch (elem)
			{
				case('-'): a = b - a; break;
				case('+'): a = b + a; break;
				case('*'): a = b * a; break;
				case('/'): 
					if (a == 0)
					{
						std::cout << "Error impossible to divide by 0" << std::endl;
						return false;
					}
					a = b / a; break;
			}
			res.push(a);
		}
	}
	if (res.size() != 1)
	{
		std::cout << "Error : Wrong input format" <<std::endl;
		return false;
	}
	std::cout << res.top() << std::endl;
	return true;
}
