/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 17:05:08 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main()
{
    try
    {
        Bureaucrat high("high", Grade(1));
        Bureaucrat low("low", Grade(150));

        ShrubberyCreationForm spaceShip("Heart of Gold");

        low.signForm(spaceShip);
        low.executeForm(spaceShip);
        high.signForm(spaceShip);
        low.executeForm(spaceShip);
        high.executeForm(spaceShip);

        RobotomyRequestForm marvin("Marvin");
        low.signForm(marvin);
        low.executeForm(marvin);
        high.signForm(marvin);
        low.executeForm(marvin);
        high.executeForm(marvin);

        PresidentialPardonForm ford("Ford Prefect");
        low.signForm(ford);
        low.executeForm(ford);
        high.signForm(ford);
        low.executeForm(ford);
        high.executeForm(ford);
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
