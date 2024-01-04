/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:51:11 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 16:46:11 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	const int _enPoint;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& ScavTrap);
	ScavTrap& operator=(ScavTrap const & ScavTrap);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
};

#endif