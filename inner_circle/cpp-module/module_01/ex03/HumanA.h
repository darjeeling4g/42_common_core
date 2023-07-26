/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:10:31 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 16:36:43 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX03_HUMANA_H_
#define MODULE01_EX03_HUMANA_H_

#include <iostream>
#include "Weapon.h"

using std::string;

class HumanA
{

public:
    HumanA(string name, Weapon& weapon);
    ~HumanA();
    HumanA& attack();

private:
    string name;
    Weapon& weapon;

};

#endif // !MODULE01_EX03_HUMANA_H_
