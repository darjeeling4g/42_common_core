/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:09:27 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 16:42:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX03_WEAPON_H_
#define MODULE01_EX03_WEAPON_H_

#include <string>

using std::string;

class Weapon
{

public:
    Weapon(string type);
    ~Weapon();
    const string& getType() const;
    Weapon &setType(string type);
    
private:
    string type;
};

#endif // !MODULE01_EX03_WEAPON_H_
