/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:38:38 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/12 13:16:25 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string str);
private :
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif