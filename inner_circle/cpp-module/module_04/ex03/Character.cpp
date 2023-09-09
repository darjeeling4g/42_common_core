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
            if (_slots[i])
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
        delete _slots[i];
    }
}

std::string const & Character::getName()
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
    _slots[idx] = NULL;
}


void Character::use(int idx, ICharacter& target) 
{

}
