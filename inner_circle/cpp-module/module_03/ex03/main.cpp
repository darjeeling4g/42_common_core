/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:04:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 17:35:38 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

int main()
{
    DiamondTrap mk4("MK-4");

    mk4.attack("MK-4");
    mk4.takeDamage(10);
    mk4.beRepaired(15);
    mk4.guardGate();
    mk4.highFivesGuys();
    mk4.whoAmI();
    mk4.takeDamage(100);
    mk4.beRepaired(50);
}
