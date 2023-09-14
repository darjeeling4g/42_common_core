/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:39:11 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:02:11 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        _memory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_memory[i] != NULL)
            {
                delete _memory[i];
                _memory[i] = NULL;
            }
            if (copy._memory[i])
            {
                _memory[i] = copy._memory[i]->clone();
            }
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_memory[i] != NULL)
        {
            delete _memory[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_memory[i] == NULL)
            {
                _memory[i] = m->clone();
                break;
            }
        }
        delete m;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_memory[i]->getType() == type)
        {
            return (_memory[i]->clone());  
        }
    }
    return (0);
}
