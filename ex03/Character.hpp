/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:33:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:49:26 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "Amateria.hpp"


class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	int _is_empty[4];

public:
	Character();
	Character(std::string name);
	Character(Character const & copy);
	Character & operator=(Character const & character);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif