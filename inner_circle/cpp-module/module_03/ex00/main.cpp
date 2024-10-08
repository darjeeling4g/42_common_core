/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:04:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/23 18:25:08 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    ClapTrap mk1("MK-1");
    ClapTrap duplicant(mk1);

    mk1.attack("MK-2");
    mk1.takeDamage(3);
    mk1.beRepaired(4);
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    mk1.attack("MK-2");
    std::cout << "===========duplicant==============" << std::endl;
    duplicant.takeDamage(11);
    duplicant.beRepaired(11);
}
