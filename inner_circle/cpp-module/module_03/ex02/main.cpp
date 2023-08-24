/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:04:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 13:08:01 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

int main()
{
    FragTrap mk3("MK-3");

    mk3.attack("MK-3");
    mk3.takeDamage(10);
    mk3.beRepaired(15);
    mk3.highFivesGuys();
    mk3.takeDamage(100);
    mk3.beRepaired(50);
}
