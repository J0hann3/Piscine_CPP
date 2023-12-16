/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:20:59 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/16 20:33:04 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
	WrongCat();
	WrongCat(WrongCat const &WrongCat);
	WrongCat const & operator=(WrongCat const & WrongCat);
	~WrongCat();
	void makeSound() const;
};

#endif