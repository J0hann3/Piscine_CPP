/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:44:02 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/09 20:24:19 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
protected:
	std::string _name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& clapTrap);
	ClapTrap& operator=(ClapTrap const & clapTrap);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);



	// std::string getName(void) const;
	// void setName(std::string name);
	// int getHitPoint(void) const;
	// void setHitPoint(int hitPoint);
	// int getEnergyPoint(void) const;
	// void setEnergyPoint(int energyPoint);
	// int getAttackDamage(void) const;
	// void setAttackDamage(int attackDamage);
};

#endif