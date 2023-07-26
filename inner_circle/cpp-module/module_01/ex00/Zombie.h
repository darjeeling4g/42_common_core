/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:27:48 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 13:02:23 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX00_ZOMBIE_H_
#define MODULE01_EX00_ZOMBIE_H_

#include <iostream>

using std::string;

class Zombie
{

public:
    Zombie( string name );
    ~Zombie();
    void announce(void);

private:
    string name;

}; 

Zombie* newZombie(string name);
void randomChump(string name);

#endif
