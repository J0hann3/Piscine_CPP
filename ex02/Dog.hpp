/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 14:08:47 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private :
	Brain *_brain;
public :
	Dog();
	Dog(Dog const &Dog);
	Dog const & operator=(Dog const & Dog);
	~Dog();
	virtual void makeSound() const;
};

#endif