/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:36:52 by siyang            #+#    #+#             */
/*   Updated: 2023/08/01 15:34:20 by siyang           ###   ########.fr       */
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
    int i;
    std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (i = 0; i < 4; i++)
    {
        if (arr[i] == level) 
            break;
    }
    switch (i)
    {
        case DEBUG:
            (this->*funcPointer[DEBUG])();
        case INFO:
            (this->*funcPointer[INFO])();
        case WARNING:
            (this->*funcPointer[WARNING])();
        case ERROR:
            (this->*funcPointer[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
    std::cout << "I really do!\n";
    std::cout << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
    std::cout << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
    std::cout << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    std::cout << std::endl;
}
