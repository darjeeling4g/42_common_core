/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:33:25 by siyang            #+#    #+#             */
/*   Updated: 2023/07/19 23:47:54 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() 
    : index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
    contacts[index] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    if (index == 7)
    {
        index = 0;
    }
    else
    {
        index++;
    }
}

void PhoneBook::DisplayPhoneBook() const
{
    int index = 0;

    std::cout << '\n'<< std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "FirstName" << "|";
    std::cout << std::setw(10) << "LastName" << "|";
    std::cout << std::setw(10) << "NickName" << "|";
    std::cout << std::endl;
    while (index < 8)
    {
        std::cout << std::setw(10) << index + 1 << "|";
        DisplayField(contacts[index].getFirstName());
        DisplayField(contacts[index].getLastName());
        DisplayField(contacts[index].getNickName());
        std::cout << std::endl;
        index++;
    }
    std::cout << std::endl;
}

void PhoneBook::DisplayField(const string field) const
{
    if (field.length() <= 10)
    {
        std::cout << std::setw(10) << field << "|";
    }
    else
    {
        std::cout << field.substr(0, 9) << ".|";
    }
}

void PhoneBook::DisplayContact(int index) const
{
    if (index > 0 && index < 9)
    {
        if (contacts[index - 1].getFirstName() == "")
        {
            std::cout << "=== Failure: No contact ===\n" << std::endl; 
        }
        else
        { 
            std::cout << "First name: " << contacts[index - 1].getFirstName() << '\n';
            std::cout << "Last name: " << contacts[index - 1].getLastName() << '\n';
            std::cout << "Nick name: " << contacts[index - 1].getNickName() << '\n';
            std::cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << '\n';
            std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << '\n';
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "=== Failure: Out of range ===\n" << std::endl; 
    }
}
