/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:00:28 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 13:09:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    Zombie* zombie;

    zombie = newZombie("Foo");
    zombie->announce();
    delete zombie;
    randomChump("Bar");
    return (0);
}
