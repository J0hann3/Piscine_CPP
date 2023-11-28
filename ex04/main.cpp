/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:27:33 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/27 13:12:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

int main(int argc, char *argv[])
{
	if (argc =! 4)
		std::cout << "Error : number of arguments invalid" << std::enld;
	
	std::ifstream ifs(argv[1], std::ifstream::in);
	std::string filename1 (argv[1].append(".replace"))


	ifs.close();
}
