/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:03:53 by siyang            #+#    #+#             */
/*   Updated: 2024/01/16 22:26:13 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename Iter> void printContainer(Iter begin, Iter end)
{
    for (; begin != end; begin++)
    {
        std::cout << *begin << std::endl;
    }
}

int main()
{
    std::cout << "=======vector========" << std::endl;

    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        printContainer<std::vector<int>::iterator>(vec.begin(), vec.end());
        std::cout << *easyfind(vec, 3) << std::endl;
        std::cout << *easyfind(vec, 6) << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }

    std::cout << "========list=========" << std::endl;

    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    try
    {
        printContainer<std::list<int>::iterator>(lst.begin(), lst.end());
        std::cout << *easyfind(lst, 3) << std::endl;
        std::cout << *easyfind(lst, 6) << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }

    std::cout << "========deque========" << std::endl;

    std::deque<int> deq;

    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);

    try
    {
        printContainer<std::deque<int>::iterator>(deq.begin(), deq.end());
        std::cout << *easyfind(deq, 3) << std::endl;
        std::cout << *easyfind(deq, 6) << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
