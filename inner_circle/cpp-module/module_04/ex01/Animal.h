/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:00:42 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:59:12 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX00_ANIMAL_H_
#define MODULE04_EX00_ANIMAL_H_

#include <iostream>
#include <string>

class Animal
{
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;

protected:
    Animal& setType(std::string type);
    std::string type;
};

#endif // !MODULE04_EX00_ANIMAL_H_
