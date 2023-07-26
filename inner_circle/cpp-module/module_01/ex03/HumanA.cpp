/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:50:13 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 16:35:01 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(string name, Weapon& weapon)
  : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

HumanA& HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    return (*this);
}
