/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:40:31 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 17:39:52 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name), FragTrap(name), ScavTrap(name), name(name) 
{
    ClapTrap::name = name + "_clap_name";
    hitPoint = FRAG_HIT;
    energyPoint = SCAV_ENERGY;
    attackDamage = FRAG_DAMAGE;
    energyLimit = SCAV_ENERGY;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
  : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), name(copy.name)
{
    ClapTrap::name = copy.getName() + "_clap_name";
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
    std::cout << "DiamondTrap Copy assigment operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::name = copy.getName() + "_clap_name";
        name = copy.getName();   
        hitPoint = copy.getHitPoint();
        energyPoint = copy.getEnergyPoint();
        attackDamage = copy.getAttackDamage();
        energyLimit = copy.getEnergyLimit();
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap My name is " << name << ", and clap_name is " << ClapTrap::name << std::endl; 
}
