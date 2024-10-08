/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 13:50:19 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int main()
{
    try
    {
        Form form("topSecret", 1, 1);

        std::cout << form;

        Bureaucrat low("low", 150);
        Bureaucrat high("high", 1);

        std::cout << low << high;

        high.signForm(form);
        high.signForm(form);
        std::cout << form;
        low.signForm(form);

        // @error case
        Form wrongForm("wrongForm", 0, 0);
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
