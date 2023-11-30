/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:45:32 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 17:16:07 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

int main()
{
    try
    {
        Form form("topSecret", 1, 1);

        std::cout << form;

        Bureaucrat bureaucrat("low", 150);
        // @error case
        Form wrongForm("wrongForm", 0, 0);
    }
    catch (const std::exception& expn)
    {
        std::cout << expn.what() << std::endl;
    }
    return (0);
}
