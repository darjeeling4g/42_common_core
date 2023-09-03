/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:00:38 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 22:04:44 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
  : type("Invisible dragon") 
{
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
  : type(type) 
{
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
  : type(copy.type)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

WrongAnimal& WrongAnimal::setType(std::string type)
{
    this->type = type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "🐲: Kuaaaaa, the strongest among dragons the invisible dragon roared" << std::endl;
}
