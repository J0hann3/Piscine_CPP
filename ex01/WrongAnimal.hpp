/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/04 18:30:31 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
protected :
	std::string type;
public :
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const &animal);
	WrongAnimal & operator=(WrongAnimal const & animal);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};

#endif