/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:08:11 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 17:34:23 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
public:
	Zombie(std::string str);
	~Zombie();
	void announce(void);
private :
	std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif