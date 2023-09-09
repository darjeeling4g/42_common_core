/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:37:59 by siyang            #+#    #+#             */
/*   Updated: 2023/09/01 00:57:24 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_CURE_H_
#define MODULE04_EX03_CURE_H_

#include <iostream>
#include "AMateria.h"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure& copy);
    Cure& operator=(const Cure& copy);
    virtual ~Cure();
    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};

#endif
