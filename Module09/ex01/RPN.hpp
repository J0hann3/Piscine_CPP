/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:25:18 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/25 14:54:26 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>
# include <iostream>

class RPN
{
private:
	std::stack<char> _input;
public:
	RPN();
	RPN(RPN const & copy);
	RPN & operator=(RPN const & assign);
	~RPN();
	bool fill(std::string str);
	bool calculate();
};

#endif