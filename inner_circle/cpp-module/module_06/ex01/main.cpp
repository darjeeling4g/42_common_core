/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:47:08 by siyang            #+#    #+#             */
/*   Updated: 2024/01/03 17:00:45 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

#include <iostream>

int main()
{
    Data str;
    uintptr_t strPtr;
    Data* strPtr2;

    str.data = "bla bla";

    std::cout << "before Serialize: " << std::hex << &str << std::dec << "(address) " << str.data << "(value)"
              << std::endl;

    strPtr = Serializer::serialize(&str);
    std::cout << "after Serialize: " << std::hex << strPtr << std::dec << std::endl;

    strPtr2 = Serializer::deserialize(strPtr);
    std::cout << "after Deserialize: " << std::hex << strPtr2 << std::dec << "(address) " << strPtr2->data << "(value)"
              << std::endl;
}
