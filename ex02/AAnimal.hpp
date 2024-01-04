/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:36:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class AAnimal
{
protected :
	std::string type;
public :
	AAnimal();
	AAnimal(std::string type);
	AAnimal(AAnimal const &animal);
	AAnimal & operator=(AAnimal const & animal);
	virtual ~AAnimal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif