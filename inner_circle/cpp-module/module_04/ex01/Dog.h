/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:47 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:58:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_DOG_H_
#define MODULE04_EX03_DOG_H_

#include "Animal.h"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    virtual ~Dog();
    virtual void makeSound() const;
};

#endif // !MODULE04_EX03_DOG_H_
