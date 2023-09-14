/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:10:18 by siyang            #+#    #+#             */
/*   Updated: 2023/09/14 14:18:29 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_AMATERIA_H_
#define MODULE04_EX03_AMATERIA_H_

#include <iostream>
#include <string>
#include "ICharacter.h"

class AMateria
{
protected:
    const std::string _type;
public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
