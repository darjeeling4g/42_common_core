/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:02:34 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:59:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "MateriaSource.h"
#include "Character.h"
#include "Ice.h"
#include "Cure.h"

void   check_leak(void)
{
		system("leaks interface");
}

int main()
{		
    atexit(check_leak);

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "============================" << std::endl;

    AMateria* floor[10];
    for (int i = 0; i < 10; i++)  
        floor[i] = NULL;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    me = new Character("siyang");
    bob = new Character("bob");
    floor[0] = src->createMateria("ice");
    floor[1] = src->createMateria("cure");
    me->equip(floor[0]);
    me->equip(floor[1]);
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    for (int i = 0; i < 10; i++)
    {
        if (floor[i] != NULL)
        {
            delete floor[i];
        }
    }

    return 0;
}
