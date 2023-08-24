/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:04:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 17:46:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main()
{
    ScavTrap mk2("MK-2");

    mk2.attack("MK-2");
    mk2.takeDamage(10);
    mk2.beRepaired(15);
    mk2.guardGate();
    mk2.takeDamage(100);
    mk2.beRepaired(50);
}
