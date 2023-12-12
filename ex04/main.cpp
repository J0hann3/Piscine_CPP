/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:27:33 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 13:57:41 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void write_in_file(std::ifstream& ifs, std::ofstream& ofs, std::string str_change, std::string str_find)
{
	std::string buffer;
	std::string line;

	while (!(ifs.eof() || ifs.bad()))
	{
		std::getline(ifs, line);
		buffer += line;
		if (!ifs.eof())
			buffer += '\n';
	}

	int old_pos = 0;
	int new_pos = 0;
	while(1)
	{
		size_t found = buffer.find(str_find, old_pos);
		if (found != std::string::npos)
		{
			new_pos = found;
			ofs << buffer.substr(old_pos, new_pos - old_pos);
			ofs << str_change;
			old_pos = new_pos + str_find.size();
		}
		else
			break;
	}
	ofs << buffer.substr(old_pos);
}

int replace(char *argv[])
{
	std::string str_find = argv[2], str_change = argv[3];
	if (str_find.empty() == true)
	{
		std::cout << "Error : Empty string given in argument" << std::endl;
		return 1;
	}
	std::ifstream ifs(argv[1], std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Error :Invalid filename" <<std::endl;
		return 1;
	}
	std::string filename1 (argv[1]);
	filename1.append(".replace");
	std::ofstream ofs (filename1.c_str(), std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Error : Can open file" <<std::endl;
		return 1;
	}
	write_in_file(ifs, ofs, str_change, str_find);
	ifs.close();
	ofs.close();
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error : number of arguments invalid" << std::endl;
		return 1;
	}
	return replace(argv);
}
