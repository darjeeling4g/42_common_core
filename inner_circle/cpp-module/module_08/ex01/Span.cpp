/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:59:36 by siyang            #+#    #+#             */
/*   Updated: 2024/01/17 16:34:04 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
    _vec.reserve(n);
}

Span::Span(const Span& copy)
{
    *this = copy;
}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
        this->_vec.clear();
        this->_vec = copy._vec;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (_vec.size() < _vec.capacity())
    {
        _vec.push_back(num);
    }
    else
    {
        throw std::length_error("Out of range, Insufficient storage space.");
    }
}

unsigned int Span::shortestSpan() const
{
    if (_vec.size() < 2)
    {
        throw std::runtime_error("Too few elements in stroage.");
    }

    std::vector<int> temp = _vec;

    std::sort(temp.begin(), temp.end());
    std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
    std::transform(temp.begin(), temp.end(), temp.begin(), functor());
    return (*std::min_element(temp.begin() + 1, temp.end()));
}

unsigned int Span::longestSpan() const
{
    if (_vec.size() < 2)
    {
        throw std::runtime_error("Too few elements in stroage.");
    }
    return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}
