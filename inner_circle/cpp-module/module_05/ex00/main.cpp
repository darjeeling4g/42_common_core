/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 12:57:16 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main()
{
    try
    {
        Bureaucrat high("high", 1);
        Bureaucrat low("low", 150);

        std::cout << high << low;

        high.decreaseGrade();
        low.increaseGrade();
        std::cout << high << low;

        // @error case
        low.decreaseGrade().decreaseGrade();
        high.increaseGrade().increaseGrade();
        std::cout << high << low;

        Bureaucrat tooHigh("tooHigh", 0);
        Bureaucrat tooLow("tooLow", 151);
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
