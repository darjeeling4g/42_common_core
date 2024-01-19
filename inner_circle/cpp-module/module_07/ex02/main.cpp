/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:56:29 by siyang            #+#    #+#             */
/*   Updated: 2024/01/11 17:59:31 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

void leaks()
{
    system("leaks template");
}

int main()
{
    atexit(leaks);

    try
    {
        Array<int> intArr;

        std::cout << "size: " << intArr.size() << std::endl;
        std::cout << "value: " << intArr[0] << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }

    Array<int> intArr(3);

    intArr[0] = 1;
    intArr[1] = 2;
    intArr[2] = 3;

    std::cout << "size: " << intArr.size() << std::endl;
    std::cout << "value: " << intArr[0] << " " << intArr[1] << " " << intArr[2] << std::endl;

    Array<double> doubleArr(3);

    doubleArr[0] = 3.14;
    doubleArr[1] = 2.718;
    doubleArr[2] = 1.618;

    std::cout << "size: " << doubleArr.size() << std::endl;
    std::cout << "value: " << doubleArr[0] << " " << doubleArr[1] << " " << doubleArr[2] << std::endl;

    Array<char> charArr(5);

    charArr[0] = 'a';
    charArr[1] = 'r';
    charArr[2] = 'r';
    charArr[3] = 'a';
    charArr[4] = 'y';

    std::cout << "size: " << charArr.size() << std::endl;
    std::cout << "value: " << charArr[0] << " " << charArr[1] << " " << charArr[2] << " " << charArr[3] << " "
              << charArr[4] << std::endl;

    Array<char> charArr2(4);

    charArr2[0] = 'c';
    charArr2[1] = 'o';
    charArr2[2] = 'p';
    charArr2[3] = 'y';

    charArr = charArr2;
    std::cout << "size: " << charArr2.size() << std::endl;
    std::cout << "value: " << charArr2[0] << " " << charArr2[1] << " " << charArr2[2] << " " << charArr2[3]
              << std::endl;
    std::cout << "size: " << charArr.size() << std::endl;
    std::cout << "value: " << charArr[0] << " " << charArr[1] << " " << charArr[2] << " " << charArr[3] << std::endl;
}
