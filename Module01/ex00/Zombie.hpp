/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:08:11 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/26 18:25:59 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

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