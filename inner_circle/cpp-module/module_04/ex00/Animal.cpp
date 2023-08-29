/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:00:38 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 21:56:31 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Animal::Animal()
  : type("Invisible dragon") 
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type)
  : type(type) 
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
  : type(copy.type)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

Animal& Animal::setType(std::string type)
{
    this->type = type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "🐲: Kuaaaaa, the strongest among dragons the invisible dragon roared" << std::endl;
}
