/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:43:23 by siyang            #+#    #+#             */
/*   Updated: 2023/07/19 23:07:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE00_EX01_PHONEBOOK_H_
#define MODULE00_EX01_PHONEBOOK_H_

#include <iostream>
#include <iomanip>
#include "Contact.h"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    void AddContact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret);
    void DisplayPhoneBook() const;
    void DisplayField(const string field) const;
    void DisplayContact(int index) const;

private:
    Contact contacts[8];
    int index;
};

#endif
