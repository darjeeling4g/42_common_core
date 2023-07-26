/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:21 by siyang            #+#    #+#             */
/*   Updated: 2023/07/24 14:56:20 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(string name)
  : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

HumanB& HumanB::attack()
{
    if (weapon == NULL)
    {
      std::cout << name << " attacks with their FIST" << std::endl;
    }
    else
    {
      std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    return (*this);
}

HumanB& HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
    return (*this);
}
