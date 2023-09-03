/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:40:10 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:39:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

Dog::Dog()
  : Animal("Dog") 
{
    std::cout << "Dog Default Constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    brain = new Brain();
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->setType(copy.getType());
        if (brain)
        {
            delete brain;
            brain = NULL;
        }
        brain = new Brain();
        *brain = *copy.brain;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    if (brain)
    {
        delete brain;
        brain = NULL;
    }
}

void Dog::makeSound() const
{
    std::cout << "🐶: bark" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (brain);
}
