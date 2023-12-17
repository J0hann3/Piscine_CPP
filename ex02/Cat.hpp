/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 14:08:56 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private :
	Brain *_brain;
public :
	Cat();
	Cat(Cat const &Cat);
	Cat const & operator=(Cat const & Cat);
	~Cat();
	virtual void makeSound() const;
};

#endif