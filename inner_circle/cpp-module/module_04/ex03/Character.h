/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:26:43 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:06:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_CHARACTER_H_
#define MODULE04_EX03_CHARACTER_H_

#include <string>
#include "ICharacter.h"
#include "AMateria.h"

class Character : public ICharacter
{
public:
    Character(std::string name);
    Character(const Character& copy);
    Character& operator=(const Character& copy);
    virtual ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    std::string _name; 
    AMateria* _slots[4];

};

#endif
