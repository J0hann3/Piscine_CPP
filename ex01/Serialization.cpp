/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qthierry <qthierry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:40:31 by jvigny            #+#    #+#             */
/*   Updated: 2024/01/14 13:43:38 by qthierry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{}

Serialization::Serialization(Serialization const & serialization)
{
	(void)serialization;
}

Serialization & Serialization::operator=(Serialization const & serialization)
{
	(void)serialization;
	return *this;
}

Serialization::~Serialization()
{}

uintptr_t Serialization::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
