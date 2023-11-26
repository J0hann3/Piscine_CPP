/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:30:06 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 18:37:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str("HI THIS IS BRAIN");
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of str : " <<&str << std::endl;
	std::cout << "Address of ptr_str : " << stringPTR << std::endl;
	std::cout << "Address of ref_str : " << &stringREF << std::endl << std::endl;

	std::cout << "value of str : " << str << std::endl;
	std::cout << "value of ptr_str : " << *stringPTR << std::endl;
	std::cout << "value of ref_str : " << stringREF << std::endl;
	return 0;
}