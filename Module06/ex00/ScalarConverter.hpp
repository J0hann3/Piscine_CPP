/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:05:46 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/13 18:13:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& vector);
	ScalarConverter & operator=(ScalarConverter const &vector);
	~ScalarConverter();
public:
	static void convert(std::string arg);
};

#endif