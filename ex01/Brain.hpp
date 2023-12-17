/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:35:44 by jvigny            #+#    #+#             */
/*   Updated: 2023/12/17 13:46:59 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# define SIZE_ARRAY 100

class Brain
{
private :
	std::string _ideas[SIZE_ARRAY];
	int _index;
public :
	Brain();
	Brain(Brain const &Brain);
	Brain const & operator=(Brain const & Brain);
	~Brain();
	// void addIdea(std::string idea);
	// void modifieIdea(int i,std::string idea);
	// void printAllIdeas();
};

#endif