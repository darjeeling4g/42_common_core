/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:47 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:38:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX03_DOG_H_
#define MODULE04_EX03_DOG_H_

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    virtual ~Dog();
    virtual void makeSound() const;
    Brain* getBrain() const;
private:
    Brain* brain;
};

#endif // !MODULE04_EX03_DOG_H_
