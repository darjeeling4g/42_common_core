/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:26:45 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:44:47 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"

Character::Character(std::string name)
  : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = NULL;
    }
}

Character::Character(const Character& copy)
{
    *this = copy;
}

Character& Character::operator=(const Character& copy)
{
    if (this != &copy)
    {
        _name = copy._name;
        for (int i = 0; i < 4; i++)
        {
            if (_slots[i] != NULL)
            {
                delete _slots[i];
                _slots[i] = NULL;
            }
            if (copy._slots[i])
            {
                _slots[i] = copy._slots[i]->clone();
            }
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] != NULL)
        {
            delete _slots[i];
        }
    }
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == NULL)
        {
            _slots[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (_slots[idx] != NULL)
    {
        _slots[idx] = NULL;
    }
}


void Character::use(int idx, ICharacter& target) 
{
    if(_slots[idx] != NULL)
    {
        _slots[idx]->use(target);
    }
}
