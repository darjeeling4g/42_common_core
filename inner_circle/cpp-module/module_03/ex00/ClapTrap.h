/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:04:09 by siyang            #+#    #+#             */
/*   Updated: 2023/08/23 12:22:08 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE03_EX00_CLAPTRAP_H_
#define MODULE03_EX00_CLAPTRAP_H_

#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& copy);
    virtual ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackDamage() const;

private:
    std::string name;
    int hitPoint;
    int energyPoint;
    int attackDamage;
    bool isActable();
    void PrintStatus();
};

#endif // !MODULE03_EX00_CLAPTRAP_H_
