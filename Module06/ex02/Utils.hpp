/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:55 by qthierry          #+#    #+#             */
/*   Updated: 2024/01/16 18:48:24 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif