/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:53:33 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 17:45:49 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE03_EX01_SCAVTRAP_H_
#define MODULE03_EX01_SCAVTRAP_H_

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);
    virtual ~ScavTrap();
    virtual void attack(const std::string& target);
    void guardGate();

private:
};

#endif // !MODULE03_EX01_SCAVTRAP_H_
