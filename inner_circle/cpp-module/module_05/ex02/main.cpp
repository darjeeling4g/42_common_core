/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 17:20:52 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"

int main()
{
    try
    {
        AForm form("topSecret", Grade(1), Grade(1));

        std::cout << form;

        Bureaucrat low("low", Grade(150));
        Bureaucrat high("high", Grade(1));

        std::cout << low << high;

        high.signForm(form);
        high.signForm(form);
        std::cout << form;
        low.signForm(form);

        // @error case
        AForm wrongForm("wrongForm", Grade(0), Grade(0));
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
