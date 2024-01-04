/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:58:50 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 15:35:56 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
	std::string _name;
public :
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & copy);
	DiamondTrap & operator=(DiamondTrap const & diamond);
	~DiamondTrap(void);

	void whoAmI();
};

#endif