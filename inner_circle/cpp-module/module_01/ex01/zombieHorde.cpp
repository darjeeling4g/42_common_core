/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:17:38 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 15:28:20 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, string name)
{
    Zombie *zombieHorde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombieHorde[i].setName(name);
    }
    return (zombieHorde);
}
