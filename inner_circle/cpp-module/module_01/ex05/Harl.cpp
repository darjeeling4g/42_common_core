/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:36:52 by siyang            #+#    #+#             */
/*   Updated: 2023/08/01 14:54:57 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl()
{
    funcPointer[DEBUG] = &Harl::debug; 
    funcPointer[INFO] = &Harl::info; 
    funcPointer[WARNING] = &Harl::warning; 
    funcPointer[ERROR] = &Harl::error; 
}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
    std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == level)
        {
            (this->*funcPointer[i])();
            break;
        }
    }
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}
