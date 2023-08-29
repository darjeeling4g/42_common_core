/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:40:10 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:57:13 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::Dog()
  : Animal("Dog") 
{
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
  : Animal(copy)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->setType(copy.getType());
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶: bark" << std::endl;
}
