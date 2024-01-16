/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:12:36 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/16 14:14:22 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <limits.h>
#include <float.h>


ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(ScalarConverter const& vector)
{
	(void)vector;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &vector)
{
	(void)vector;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

static void overflow()
{
	std::cout << "char: Overflow" << std::endl;
	std::cout << "int: Overflow" << std::endl;
	std::cout << "float: Overflow" <<std::endl;
	std::cout << "double: Overflow" <<std::endl;
}

static void unknown()
{
	std::cout << "char: Unknown type" << std::endl;
	std::cout << "int: Unknown type" << std::endl;
	std::cout << "float: Unknown type" <<std::endl;
	std::cout << "double: Unknown type" <<std::endl;
}

static void print_int(std::string const arg)
{
	int t_int;
	std::size_t index;

	try 
	{
		t_int = std::stoi(arg, &index, 10);
	}
	catch (std::out_of_range &e)
	{
		overflow();
		return ;
	}
	catch (std::exception &e)
	{
		unknown();
		return ;
	}
	if (index != arg.size())
	{
		unknown();
		return ;
	}
	if (t_int < 0 || t_int > CHAR_MAX)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(t_int)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<unsigned char>(t_int) << "'" << std::endl;
	std::cout << "int: " << t_int << std::endl;
	std::cout << "float: " << static_cast<float>(t_int) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(t_int) << ".0" << std::endl;
	return ;
}

static void print_double(std::string const arg)
{
	double t_double;
	std::size_t index;

	try 
	{
		t_double = std::stod(arg, &index);
	}
	catch (std::out_of_range &e)
	{
		overflow();
		return ;
	}
	catch (std::exception &e)
	{
		unknown();
		return ;
	}
	if (index != arg.size())
	{
		unknown();
		return ;
	}
	if (static_cast<int>(t_double) < 0 || static_cast<int>(t_double) > CHAR_MAX)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(t_double)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<unsigned char>(t_double) << "'" << std::endl;
	if (t_double > static_cast<double>(INT_MAX) || t_double < static_cast<double>(INT_MIN))
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(t_double) << std::endl;
	if (t_double > FLT_MAX || t_double < FLT_MIN)
		std::cout << "float: Overflow" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(t_double) << "f" << std::endl;
	std::cout << "double: " << t_double << std::endl;
	return ;
}

static void print_float(std::string arg)
{
	float t_float;
	std::size_t index;

	try 
	{
		arg.pop_back();
		t_float = std::stof(arg, &index);
	}
	catch (std::out_of_range &e)
	{
		overflow();
		return ;
	}
	catch (std::exception &e)
	{
		unknown();
		return ;
	}
	if (index != arg.size())
	{
		unknown();
		return ;
	}
	if (static_cast<int>(t_float) < 0 || static_cast<int>(t_float) > CHAR_MAX)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(t_float)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<unsigned char>(t_float) << "'" << std::endl;
	if (t_float > static_cast<float>(INT_MAX) || t_float < static_cast<float>(INT_MIN))
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(t_float) << std::endl;
	std::cout << "float: " << t_float << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(t_float) << std::endl;
	return ;
}

static void print_char(std::string arg)
{
	if (arg.size() != 3 || arg[0] != '\'' || arg[2] != '\'')
	{
		std::cout << "char: Unknown type" << std::endl;
		std::cout << "int: Unknown type" << std::endl;
		std::cout << "float: Unknown type" <<std::endl;
		std::cout << "double: Unknown type" <<std::endl;
		return;
	}
	int res = arg[1];
	if (res < 0 || res > CHAR_MAX)
		std::cout << "char: Overflow" << std::endl;
	else if (std::isprint(static_cast<unsigned char>(res)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<unsigned char>(res) << "'" << std::endl;
	std::cout << "int: " << res << std::endl;
	std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl; 

}


void ScalarConverter::convert(std::string arg)
{
	if (arg.compare("nan") == 0 || arg.compare("nanf") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (arg.compare("inff") == 0 || arg.compare("inf") == 0 ||
			arg.compare("+inff") == 0 || arg.compare("+inf") == 0)
	{
		std::cout << "char: Overflow" << std::endl;
		std::cout << "int: Overflow" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (arg.compare("-inff") == 0 || arg.compare("-inf") == 0)
	{
		std::cout << "char: Overflow" << std::endl;
		std::cout << "int: Overflow" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}

	for (unsigned long i = 0; i < arg.size(); i++)
	{
		if (arg[i] == '\'')
		{
			print_char(arg);
			return ;
		}
		else if (arg[i] == '.' && arg.size() > 1 && arg[arg.size() - 1] == 'f')
		{
			print_float(arg);
			return ;
		}
		else if (arg[i] == '.')
		{
			print_double(arg);
			return ;
		}
	}
	print_int(arg);
}
