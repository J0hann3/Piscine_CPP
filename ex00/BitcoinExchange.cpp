/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:19:09 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/29 14:45:39 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool check_date(std::string str);

bool openData(std::map<std::string, float>& map)
{
	std::ifstream ifs("data.csv", std::ifstream::in);

	if (!ifs.is_open())
	{
		std::cout << "Error : could not open \"data.csv\"" << std::endl;
		return false;
	}
	std::string line;
	std::getline(ifs, line);
	if (!ifs.eof() && line.compare("date,exchange_rate") != 0)
	{
		std::cout << "Error : invalid format of data.csv " << std::endl;
		return false;
	}
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (line.empty())
			continue;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "Error : invalid format of data.csv" << std::endl;
			return false;
		}
		std::string date = line.substr(0, pos);
		if (!check_date(date))
			return false;
		pos++;
		char *addr;
		float value = strtof(line.substr(pos).c_str(), &addr);
		if (*addr != '\0' || pos == line.size())
		{
			std::cout << "Error : invalid number value"  << std::endl;
			return false;
		}
		map.insert(std::pair<std::string, float>(date, value));
	}
	ifs.close();
	return true;
}

bool check_date(std::string str)
{
	struct tm time;

	char const *date = str.c_str();
	char *res = strptime(date, "%Y-%m-%d", &time);
	if (res == NULL || res != &date[str.size()] || str.size() != 10)
	{
		std::cout << "Error : invalid date format" << std::endl;
		return false;
	}
	time.tm_year = time.tm_year + 1900;
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (time.tm_year % 400 == 0 || (time.tm_year % 100 != 0 && time.tm_year % 4 == 0))
	{
		if (time.tm_mon == 1 && time.tm_mday > 29)
		{
			std::cout << "Error : invalid date format" << std::endl;
			return false;
		}
	}
	else
	{
		if (time.tm_mday > days[time.tm_mon])
		{
			std::cout << "Error : invalid date format" << std::endl;
			return false;
		}
	}
	size_t index = str.find("-");
	if (index != 4)
	{
		std::cout << "Error : invalid date format" << std::endl;
		return false;
	}
	index = str.find("-", 5);
	if (index != 7)
	{
		std::cout << "Error : invalid date format" << std::endl;
		return false;
	}
	return true;
}

bool check_format(std::pair<std::string, float>& pair)
{
	if (pair.second < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (pair.second > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return check_date(pair.first);
}

void print_exchange(std::map<std::string, float>& map, std::pair<std::string, float> & pair)
{
	for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++)
	{
		if (it->first.compare(pair.first) > 0)
		{
			if (it == map.begin())
			{
				std::cout << "Error : input date is before the beginning of the data set" << std::endl;
				return;
			}
			it--;
			std::cout << pair.first << " => " << pair.second << " = " << it->second * pair.second << std::endl;
			return;
		}
	}
	std::map<std::string, float>::iterator tmp = map.end();
	tmp--;
	std::cout << tmp->first << " => " << pair.second << " = " << tmp->second * pair.second << std::endl;
}

bool openInput(char * filename, std::map<std::string, float>& map)
{
	std::ifstream input(filename, std::ifstream::in);
	if (!input.is_open())
	{
		std::cout << "Error : could not open \"" << filename << "\"" << std::endl;
		return false;
	}
	std::string line;
	std::getline(input, line);
	if (line.compare("date | value") != 0)
	{
		std::cout << "Error : invalid format of input file" << std::endl;
		return false;
	}
	while (!input.eof())
	{
		std::getline(input, line);
		if (line.empty())
			continue;
		size_t pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cout << "Error : bad input => \"" << line << "\"" << std::endl;
			continue ;
		}
		std::pair<std::string, float> pair;
		pair.first = line.substr(0, pos);
		char *addr;
		pair.second = strtof(line.substr(pos + 3).c_str(), &addr);
		if (!check_format(pair))
			continue ;
		if (*addr != '\0' || pos + 3 == line.size())
		{
			std::cout << "Error : invalid number value"  << std::endl;
			continue ;
		}
		print_exchange(map, pair);
	}
	return true;
}
