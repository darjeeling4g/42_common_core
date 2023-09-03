/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:58:57 by siyang            #+#    #+#             */
/*   Updated: 2023/09/01 00:59:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::Ice()
  : AMateria("ice") {}

Ice::Ice(const Ice& copy)
  : AMateria(copy.getType()) {}

Ice& Ice::operator=(const Ice& copy)
{
    return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}

