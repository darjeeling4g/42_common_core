/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:41:52 by siyang            #+#    #+#             */
/*   Updated: 2023/07/18 19:07:26 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact()
    : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

Contact::~Contact() {}

string Contact::getFirstName() const
{
    return (firstName);
}

string Contact::getLastName()const
{
    return (lastName);
}

string Contact::getNickName() const
{
    return (nickName);
}

string Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

string Contact::getDarkestSecret() const
{
    return (darkestSecret);
}
