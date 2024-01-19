/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:21:37 by siyang            #+#    #+#             */
/*   Updated: 2024/01/17 17:31:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        sp.addNumber(33);
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }

    std::cout << "=====================" << std::endl;

    try
    {
        Span sp = Span(1);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }

    std::cout << "=====================" << std::endl;

    try
    {
        Span sp(100);

        int arr[10] = {0, 1};

        for (int i = 2; i < 10; ++i)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        sp.addNumber<int*>(&arr[0], &arr[9]);

        // std::vector<int> b;
        // b.push_back(32);
        // b.push_back(2345);
        // b.push_back(737);
        // b.push_back(12);
        // b.push_back(50);
        // sp.addNumber<std::vector<int>::iterator>(b.begin(), b.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
