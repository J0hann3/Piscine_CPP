/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 20:30:05 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
public :
	Cat();
	Cat(Cat const &Cat);
	Cat const & operator=(Cat const & Cat);
	~Cat();
	void makeSound() const;
};

#endif