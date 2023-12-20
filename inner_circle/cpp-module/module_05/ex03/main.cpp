/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/12/20 15:10:46 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Intern.h"

void leakCheck()
{
    system("leaks Bureaucrat");
}

int main()
{
    atexit(leakCheck);
    try
    {
        Intern intern;
        AForm* FormA = intern.makeForm("shrubbery creation", "Heart of Gold");
        AForm* FormB = intern.makeForm("robotomy request", "Marvin");
        AForm* FormC = intern.makeForm("presidential pardon", "Ford Prefect");

        Bureaucrat high("high", Grade(1));
        Bureaucrat low("low", Grade(150));

        low.signForm(*FormA);
        low.executeForm(*FormA);
        high.signForm(*FormA);
        low.executeForm(*FormA);
        high.executeForm(*FormA);

        std::cout << std::endl;

        low.signForm(*FormB);
        low.executeForm(*FormB);
        high.signForm(*FormB);
        low.executeForm(*FormB);
        high.executeForm(*FormB);

        std::cout << std::endl;

        low.signForm(*FormC);
        low.executeForm(*FormC);
        high.signForm(*FormC);
        low.executeForm(*FormC);
        high.executeForm(*FormC);

        std::cout << std::endl;

        delete (FormA);
        delete (FormB);
        delete (FormC);
        AForm* FormD = intern.makeForm("No", "type");
        low.signForm(*FormD);
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
