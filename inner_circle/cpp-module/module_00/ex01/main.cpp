/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:21:55 by siyang            #+#    #+#             */
/*   Updated: 2023/07/26 18:51:22 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstdio>
#include "PhoneBook.h"

#define FAIL (-1)

enum
{
    COMMAND,
    FIRSTNAME,
    LASTNAME,
    NICKNAME,
    PHONENUMBER,
    SECRET,
};

int getNumberInput(string prompt)
{
    int input;

    std::cout << prompt;
    std::cin >> input;
    if (std::cin.fail())
    {
        std::cout << "=== Failure: Your input is not a number ===\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return (-1);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return (input);
}

string getStringInput(string prompt)
{
    string input;

    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::clearerr(stdin);
        std::cin.clear();
        std::cout << std::endl;
    }
    return(input);
}

bool isCompleteField(const string input[7])
{
    if (input[FIRSTNAME].empty() || input[FIRSTNAME].find_first_not_of(' ', 0) == std::string::npos)
        return (false);
    if (input[LASTNAME].empty() || input[LASTNAME].find_first_not_of(' ', 0) == std::string::npos)
        return (false);
    if (input[NICKNAME].empty() || input[NICKNAME].find_first_not_of(' ', 0) == std::string::npos)
        return (false);
    if (input[PHONENUMBER].empty() || input[PHONENUMBER].find_first_not_of(' ', 0) == std::string::npos)
        return (false);
    if (input[SECRET].empty() || input[SECRET].find_first_not_of(' ', 0) == std::string::npos)
        return (false);
    return (true);
}

int main(void)
{
    PhoneBook myPhoneBook;
    string input[6];
    int index;

    while (true)
    {
        input[COMMAND] = getStringInput(">>> (ADD or SEARCH or EXIT): ");
        if (input[COMMAND] == "ADD")
        {
            std::cout << '\n';
            input[FIRSTNAME] = getStringInput("- Your first name: ");
            input[LASTNAME] = getStringInput("- Your last name: ");
            input[NICKNAME] = getStringInput("- Your nick name: ");
            input[PHONENUMBER] = getStringInput("- Your phone number: ");
            input[SECRET] = getStringInput("- Your darkest secret: ");
            if (isCompleteField(input))
            {
                myPhoneBook.AddContact(input[FIRSTNAME], input[LASTNAME], input[NICKNAME], input[PHONENUMBER], input[SECRET]);
                std::cout << "=== Success: A new contact has been added ===\n" << std::endl; 
            }
            else
            {
                std::cout << "=== Failure: You must fill in all fields ===\n" << std::endl;
            }
        }
        else if (input[COMMAND] == "SEARCH")
        {
            myPhoneBook.DisplayPhoneBook();
            index = getNumberInput("- Index number you want to search: ");
            if (index != FAIL)
            {
                myPhoneBook.DisplayContact(index);
            }
        }
        else if (input[COMMAND] == "EXIT")
        {
            break ;
        }
    }
    return 0;
}
