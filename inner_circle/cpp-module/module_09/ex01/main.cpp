/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:51 by siyang            #+#    #+#             */
/*   Updated: 2024/02/08 18:36:36 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
    (void)argv;
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Error");
        }
        RPN rpn;
        rpn.calculate(argv[1]);
        std::cout << rpn.top() << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
