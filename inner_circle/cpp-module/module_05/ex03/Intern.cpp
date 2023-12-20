/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:50 by siyang            #+#    #+#             */
/*   Updated: 2023/12/20 15:03:50 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string type, std::string name)
{
    std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (types[i] == type)
        {
            std::cout << "Intern creates "
                      << "'" << type << " -> " << name << "'" << std::endl;
            switch (i)
            {
            case SHRUBBERY:
                return (new ShrubberyCreationForm(name));
            case ROBOTOMY:
                return (new RobotomyRequestForm(name));
            case PARDON:
                return (new PresidentialPardonForm(name));
            }
        }
    }
    throw NoFormTypeException();
    return (NULL);
}
