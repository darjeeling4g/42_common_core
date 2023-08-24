/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:05:41 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 12:27:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoint(10), energyPoint(10), attackDamage(0), energyLimit(10)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage, int energyLimit)
    : name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage), energyLimit(energyLimit)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : name(copy.getName()), hitPoint(copy.getHitPoint()), energyPoint(copy.getEnergyPoint()), attackDamage(copy.getAttackDamage()), energyLimit(copy.getEnergyLimit())
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "ClapTrap Copy assigment operator called" << std::endl;
    if (this != &copy) 
    {
        name = copy.getName();
        hitPoint = copy.getHitPoint();
        energyPoint = copy.getEnergyPoint();
        attackDamage = copy.getAttackDamage();
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (isActable() == true)
    {
        std::cout << "ClapTrap " << name << " 'attacks' " << target;
        std::cout << ", causing " << attackDamage << " points of damage! - ";
        energyPoint--;
    }
    PrintStatus();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " 'take' " << amount << " damage - ";
    hitPoint -= amount;
    if (hitPoint < 0)
    {
        hitPoint = 0;
    }
    PrintStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (isActable() == true)
    {
        std::cout << "ClapTrap " << name << " 'repairs' " << amount << " hit point - ";
        hitPoint += amount;
        if (hitPoint > energyLimit)
        {
            hitPoint = energyLimit; 
            std::cout <<"((( Perfectly repaired ))) - ";
        }
        energyPoint--;
    }
    PrintStatus();
}

bool ClapTrap::isActable()
{
    if (hitPoint == 0)
    {
        std::cout << "((( No more hit point ))) - ";
        return (false);
    }
    else if (energyPoint == 0)
    {
        std::cout << "((( No more energy point ))) - ";
        return (false);
    }
    return (true);
}

void ClapTrap::PrintStatus()
{
    std::cout << "[ Hit point : " << hitPoint << " | Energy point : " << energyPoint << " ]" << std::endl;
}

std::string ClapTrap::getName() const
{
    return (name);
}

int ClapTrap::getHitPoint() const
{
    return (hitPoint);
}

int ClapTrap::getEnergyPoint() const
{
    return (energyPoint);
}

int ClapTrap::getAttackDamage() const
{
    return (attackDamage);
}

int ClapTrap::getEnergyLimit() const
{
    return (energyLimit);
}

