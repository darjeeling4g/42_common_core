/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:30:02 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 15:15:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    Zombie* horde;

    horde = zombieHorde(5, "Foo");
    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
    delete []horde;
    return (0);
}
