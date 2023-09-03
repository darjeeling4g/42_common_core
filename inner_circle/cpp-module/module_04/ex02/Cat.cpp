/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:51 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:41:20 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat()
  : Animal("Cat") 
{
    std::cout << "Cat Default Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& copy)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    brain = new Brain();
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
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

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    if (brain)
    {
        delete brain;
        brain = NULL;
    }
}

void Cat::makeSound() const
{
    std::cout << "🐱: meow" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (brain);
}
