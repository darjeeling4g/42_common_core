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
    virtual std::string const & getName();
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    std::string _name; 
    AMateria* _slots[4];

};

#endif
