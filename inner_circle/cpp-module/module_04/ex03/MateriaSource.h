/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:38:15 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 13:52:04 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_MATERIASOURCE_H_
#define MODULE04_EX03_MATERIASOURCE_H_

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& copy);
    MateriaSource& operator=(const MateriaSource& copy);
    virtual ~MateriaSource();
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);

private:
    AMateria* _memory[4];
};

#endif
