/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:37:59 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 13:07:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap(std::string name)
  : ClapTrap(name, 100, 100, 30, 100)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
  : ClapTrap(copy.getName(), copy.getHitPoint(), copy.getEnergyPoint(), copy.getAttackDamage(), copy.getEnergyLimit())
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap Copy assigment operator called" << std::endl;
    if (this != &copy)
    {
        name = copy.getName();   
        hitPoint = copy.getHitPoint();
        energyPoint = copy.getEnergyPoint();
        attackDamage = copy.getAttackDamage();
        energyLimit = copy.getEnergyLimit();
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (isActable() == true)
    {
        std::cout << "FragTrap " << name << " want to highFive! - ";
        energyPoint--;
    }
    PrintStatus();
}
