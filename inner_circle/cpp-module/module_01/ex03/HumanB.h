/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:11:05 by siyang            #+#    #+#             */
/*   Updated: 2023/07/24 14:50:23 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX03_HUMANB_H_
#define MODULE01_EX03_HUMANB_H_

#include <iostream>
#include "Weapon.h"

using std::string;

class HumanB
{

public:
    HumanB(string name);
    ~HumanB();
    HumanB& attack();
    HumanB& setWeapon(Weapon& weapon);

private:
    string name;
    Weapon* weapon;

};

#endif // !MODULE01_EX03_HUMANB_H_
