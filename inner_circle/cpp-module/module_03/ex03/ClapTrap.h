/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:04:09 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 15:58:07 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE03_EX02_CLAPTRAP_H_
#define MODULE03_EX02_CLAPTRAP_H_

#include <iostream>
#include <string>

#define CLAP_HIT (10)
#define CLAP_ENERGY (10)
#define CLAP_DAMAGE (0)

class ClapTrap
{
public:
    ClapTrap(std::string name);
    ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage, int energyLimit);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);
    virtual ~ClapTrap();
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackDamage() const;
    int getEnergyLimit() const;

protected:
    std::string name;
    int hitPoint;
    int energyPoint;
    int attackDamage;
    int energyLimit; 
    bool isActable();
    void PrintStatus();
};

#endif // !MODULE03_EX01_CLAPTRAP_H_
