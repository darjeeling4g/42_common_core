/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:43:27 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 16:22:06 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, Grade(25), Grade(5))
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    return (dynamic_cast<PresidentialPardonForm&>(AForm::operator=(copy)));
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    checkExecutable(executor);
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
