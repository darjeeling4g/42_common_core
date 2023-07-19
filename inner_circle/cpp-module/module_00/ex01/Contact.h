/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:41:57 by siyang            #+#    #+#             */
/*   Updated: 2023/07/18 19:06:31 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE00_EX01_CONTACT_H_
#define MODULE00_EX01_CONTACT_H_

#include <string>

using std::string;

class Contact
{
public:
    Contact();
    Contact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret);
    ~Contact();
    string getFirstName () const;
    string getLastName() const;
    string getNickName() const;
    string getPhoneNumber() const;
    string getDarkestSecret() const;

private:
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkestSecret;
};

#endif
