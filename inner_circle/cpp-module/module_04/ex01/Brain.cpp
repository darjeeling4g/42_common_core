/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:37:19 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:45:26 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "no idea";
    }
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::setFirstIdea(std::string idea)
{
    ideas[0] = idea;
    return (*this);
}

void Brain::printFirstIdea() const
{
    std::cout << ideas[0] << std::endl;
}


