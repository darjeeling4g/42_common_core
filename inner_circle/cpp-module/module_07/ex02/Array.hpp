/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:56:20 by siyang            #+#    #+#             */
/*   Updated: 2024/01/11 18:01:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T> class Array
{
  public:
    explicit Array(std::size_t n = 0);
    Array(const Array& copy);
    Array<T>& operator=(const Array& copy);
    T& operator[](std::size_t n);
    const T& operator[](std::size_t n) const;
    ~Array();
    std::size_t size() const throw();

  private:
    T* arr;
    std::size_t len;
};

template <typename T> Array<T>::Array(std::size_t n)
{
    arr = new T[n];
    len = n;
}

template <typename T> Array<T>::Array(const Array& copy)
{
    *this = copy;
}

template <typename T> Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
        arr = new T[copy.len];
        for (std::size_t i = 0; i < copy.len; i++)
        {
            arr[i] = copy[i];
        }
        len = copy.len;
    }
    return (*this);
}

template <typename T> T& Array<T>::operator[](std::size_t n)
{
    if (n >= len)
    {
        throw std::out_of_range("attempt to access elements out of defined range.");
    }
    return (arr[n]);
}

template <typename T> const T& Array<T>::operator[](std::size_t n) const
{
    if (n >= len)
    {
        throw std::out_of_range("attempt to access elements out of defined range.");
    }
    return (arr[n]);
}

template <typename T> Array<T>::~Array()
{
    if (arr != NULL)
    {
        delete[] arr;
        arr = NULL;
    }
}

template <typename T> std::size_t Array<T>::size() const throw()
{
    return (len);
}
