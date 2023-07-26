/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:27:48 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 15:30:12 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX00_ZOMBIE_H_
#define MODULE01_EX00_ZOMBIE_H_

#include <iostream>

using std::string;

class Zombie
{

public:
    Zombie();
    Zombie( string name );
    ~Zombie();
    void announce(void);
    Zombie& setName(string name);

private:
    string name;

}; 

Zombie* zombieHorde(int N, string name);

#endif
