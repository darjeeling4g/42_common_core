/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:51 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:57:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

Cat::Cat()
  : Animal("Cat") 
{
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& copy)
  : Animal(copy)
{
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->setType(copy.getType());
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐱: meow" << std::endl;
}
