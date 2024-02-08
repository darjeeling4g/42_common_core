/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:35:22 by siyang            #+#    #+#             */
/*   Updated: 2024/01/22 14:44:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    // using iterator = typename std::stack<T>::container_type::iterator;
    // using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
    // using const_iterator = typename std::stack<T>::container_type::const_iterator;
    // using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

  public:
    MutantStack();
    MutantStack(const MutantStack& copy);
    MutantStack& operator=(const MutantStack& copy);
    ~MutantStack();
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    // const_iterator cbegin();
    // const_iterator cend();
    // const_reverse_iterator crbegin();
    // const_reverse_iterator crend();
};

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy)
{
}

template <typename T> MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy)
{
    this->c = copy;
}

template <typename T> MutantStack<T>::~MutantStack()
{
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}

// template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
// {
//     return (this->c.cbegin());
// }

// template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::cend()
// {
//     return (this->c.cend());
// }

// template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
// {
//     return (this->c.crbegin());
// }

// template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
// {
//     return (this->c.crend());
// }
