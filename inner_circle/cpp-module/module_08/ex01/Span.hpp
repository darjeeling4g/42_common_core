/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:59:40 by siyang            #+#    #+#             */
/*   Updated: 2024/01/17 17:10:49 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

class Span
{
  public:
    explicit Span(unsigned int n);
    Span(const Span& copy);
    Span& operator=(const Span& copy);
    ~Span();
    void addNumber(int num);
    template <typename Iter> void addNumber(Iter first, Iter last);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

  private:
    std::vector<int> _vec;
};

template <typename Iter> void Span::addNumber(Iter first, Iter last)
{
    std::cout << _vec.size() + std::distance(first, last) << std::endl;
    if (_vec.size() + std::distance(first, last) <= _vec.capacity())
    {
        _vec.insert(_vec.end(), first, last);
    }
    else
    {
        throw std::length_error("Out of range, Insufficient storage space.");
    }
}

struct functor
{
    int operator()(int num)
    {
        return (std::abs(num));
    }
};
