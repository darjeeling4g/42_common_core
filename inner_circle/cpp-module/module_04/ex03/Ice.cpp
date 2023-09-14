/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:58:57 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:33:49 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::Ice()
  : AMateria("ice") {}

Ice::Ice(const Ice& copy)
  : AMateria(copy.getType()) {}

Ice& Ice::operator=(const Ice& copy)
{
    (void)copy;
    return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

