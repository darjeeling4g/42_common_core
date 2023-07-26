/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:21:48 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 16:42:31 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(string type)
  : type(type) {}

Weapon::~Weapon() {}

const string& Weapon::getType() const 
{
    return (type);
}

Weapon& Weapon::setType(string type)
{
    this->type = type;
    return (*this);
}
