/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:42:34 by siyang            #+#    #+#             */
/*   Updated: 2023/09/01 00:56:35 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"

Cure::Cure()
  : AMateria("cure") {}

Cure::Cure(const Cure& copy)
  : AMateria(copy.getType()) {}

Cure& Cure::operator=(const Cure& copy)
{
    return (*this);
}

Cure::~Cure() {}

Cure* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}

