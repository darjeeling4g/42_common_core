/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:54:36 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 13:05:17 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string name)
  : ClapTrap(name, 100, 50, 20, 100)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
  : ClapTrap(copy.getName(), copy.getHitPoint(), copy.getEnergyPoint(), copy.getAttackDamage(), copy.getEnergyLimit())
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap Copy assigment operator called" << std::endl;
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (isActable() == true)
    {
        std::cout << "ScavTrap " << name << " 'attacks' " << target;
        std::cout << ", causing " << attackDamage << " points of damage! - ";
        energyPoint--;
    }
    PrintStatus();
}

void ScavTrap::guardGate()
{
    if (isActable() == true)
    {
        std::cout << "ScavTrap " << name << " is now Gatekeeper mode! - ";
        energyPoint--;
    }
    PrintStatus();
}
