/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:49:17 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/24 18:08:47 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <time.h>
# include <fstream>
# include <iostream>
# include <string>
# include <cstdlib>

bool openData(std::map<std::string, float> & map);
bool openInput(char * filename, std::map<std::string, float> & map);

#endif