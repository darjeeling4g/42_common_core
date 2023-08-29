/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:44 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:59:02 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX00_CAT_H_
#define MODULE04_EX00_CAT_H_

#include "Animal.h"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat& copy);
    Cat& operator=(const Cat& copy);
    virtual ~Cat();
    virtual void makeSound() const;
};

#endif
