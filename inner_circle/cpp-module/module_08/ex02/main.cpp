/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:35:01 by siyang            #+#    #+#             */
/*   Updated: 2024/01/22 14:47:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "========MutantStack========" << std::endl;

    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        MutantStack<int> rmstack(mstack);

        MutantStack<int>::reverse_iterator rit = rmstack.rbegin();
        MutantStack<int>::reverse_iterator rite = rmstack.rend();
        ++rit;
        --rit;
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }

    std::cout << "============list===========" << std::endl;

    {
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << list.back() << std::endl;
        list.pop_back();
        std::cout << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        //[...]
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(list);
        std::list<int>::reverse_iterator rit = s.rbegin();
        std::list<int>::reverse_iterator rite = s.rend();
        ++rit;
        --rit;
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }

    return 0;
}
