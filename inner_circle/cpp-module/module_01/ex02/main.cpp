/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:55:19 by siyang            #+#    #+#             */
/*   Updated: 2023/07/21 14:01:37 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;

int main(void)
{
    string str("HI THIS IS BRAIN");
    string* stringPTR = &str;
    string& stringREF = str;

    std::cout << "Address of 'str': " << &str << '\n';
    std::cout << "Address of 'stringPTR: " << &stringPTR << '\n';
    std::cout << "Address of 'stringREF: " << &stringREF << std::endl;

    std::cout << "Value of 'str': " << str << '\n';
    std::cout << "Value of 'stringPTR': " << *stringPTR << '\n';
    std::cout << "Value of 'stringREF': " << stringREF << std::endl;
    return (0);
}
