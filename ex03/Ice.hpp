/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:10:04 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 18:20:43 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "Amateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const & copy);
	Ice const & operator=(Ice const & materia);
	~Ice();

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif