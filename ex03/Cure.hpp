/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:12:25 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 15:30:51 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "Amateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
protected:
	
public:
	Cure();
	Cure(Cure const & copy);
	Cure const & operator=(Cure const & materia);
	~Cure();

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif