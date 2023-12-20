/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:43:33 by siyang            #+#    #+#             */
/*   Updated: 2023/12/20 15:12:26 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, Grade(72), Grade(45))
{
    std::srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    std::srand(time(0));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    return (dynamic_cast<RobotomyRequestForm&>(AForm::operator=(copy)));
}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecutable(executor);

    std::cout << "bzzzzz......";
    for (int i = 1; i < 4; i++)
    {
        std::cout << " " << i;
    }
    std::cout << " !" << std::endl;
    if (rand() % 2)
    {
        std::cout << this->getName() << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failure." << std::endl;
    }
}
