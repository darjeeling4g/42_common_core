/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:57:46 by siyang            #+#    #+#             */
/*   Updated: 2023/09/01 00:58:45 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_ICE_H_
#define MODULE04_EX03_ICE_H_

#include <iostream>
#include "AMateria.h"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& copy);
    Ice& operator=(const Ice& copy);
    virtual ~Ice();
    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};

#endif
