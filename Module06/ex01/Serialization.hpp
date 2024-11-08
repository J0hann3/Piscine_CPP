/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:31:18 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/16 18:47:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
# include "Data.hpp"
# include <stdint.h>

class Serialization
{
private:
	Serialization();
	Serialization(Serialization const & serialization);
	Serialization & operator=(Serialization const & serialization);
	~Serialization();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif