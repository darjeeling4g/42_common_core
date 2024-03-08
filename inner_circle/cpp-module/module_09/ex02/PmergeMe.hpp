/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:32:39 by siyang            #+#    #+#             */
/*   Updated: 2024/03/08 16:07:57 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

typedef std::vector<int> intVectorType;
typedef std::list<int> intListType;
typedef std::pair<int, int> intPairType;

template <typename T> class PmergeMe
{
  public:
    explicit PmergeMe();
    ~PmergeMe();
    const T& getContainer() const throw();
    const double& getTime() const throw();
    void sort(int inputSize, const char** input);

  private:
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);
    void updateJacobsthalNum();
    void recursion(std::size_t& index, int element);
    void makeMainChain(const char** input);

    // explicit template specialization
    void mergeInsertion();

  private:
  private:
    T _container;
    int _size;
    std::size_t _jacobsthalNum;
    int _cnt;
    double _time;
    std::vector<intPairType> _mainChain;
};

template <typename T> std::ostream& operator<<(std::ostream& out, const PmergeMe<T>& pmergeMe)
{
    const T& container = pmergeMe.getContainer();
    for (typename T::const_iterator iter = container.begin(); iter != container.end(); iter++)
    {
        std::cout << " " << *iter;
    }
    return (out);
}

template <typename T> PmergeMe<T>::PmergeMe() : _jacobsthalNum(3), _cnt(-1)
{
}

template <typename T> PmergeMe<T>::~PmergeMe()
{
}

template <typename T> const T& PmergeMe<T>::getContainer() const throw()
{
    return (_container);
}

template <typename T> const double& PmergeMe<T>::getTime() const throw()
{
    return (_time);
}

template <typename T> void PmergeMe<T>::updateJacobsthalNum()
{
    _jacobsthalNum = 2 * _jacobsthalNum + _cnt;
    _cnt *= -1;
    if (_jacobsthalNum > _mainChain.size())
    {
        _jacobsthalNum = _mainChain.size();
    }
}

template <typename T> void PmergeMe<T>::recursion(std::size_t& index, int element)
{
    if (index < _jacobsthalNum)
    {
        index++;
        recursion(index, _mainChain[index - 1].second);
    }
    _container.insert(std::lower_bound(_container.begin(), _container.end(), element), element);

    // print elements insert
    // std::cout << "jNum : " << _jacobsthalNum << " | "
    //           << "element : " << element << std::endl;
}

template <typename T> void PmergeMe<T>::makeMainChain(const char** input)
{
    int num1, num2;
    char* inputEnd;

    _size % 2 ? _mainChain.reserve(_size / 2 + 1) : _mainChain.reserve(_size / 2);
    for (int i = 0; i < _size; i++)
    {
        num1 = std::strtol(input[i], &inputEnd, 10);
        if (input[i] == inputEnd)
        {
            throw std::runtime_error("Error: wrong input");
        }
        i++;
        if (i == _size)
        {
            _mainChain.push_back(std::make_pair(-1, num1));
            break;
        }
        num2 = std::strtol(input[i], &inputEnd, 10);
        if (input[i] == inputEnd)
        {
            throw std::runtime_error("Error: wrong input");
        }
        num1 > num2
            ? _mainChain.insert(std::lower_bound(_mainChain.begin(), _mainChain.end(), std::make_pair(num1, num2)),
                                std::make_pair(num1, num2))
            : _mainChain.insert(std::lower_bound(_mainChain.begin(), _mainChain.end(), std::make_pair(num2, num1)),
                                std::make_pair(num2, num1));
    }
    // print mainChain
    // std::cout << "===mainChain===" << std::endl;
    // for (std::vector<intPairType>::iterator iter = _mainChain.begin(); iter != _mainChain.end(); iter++)
    // {
    //     std::cout << iter->first << " - " << iter->second << std::endl;
    // }
}

template <typename T> void PmergeMe<T>::sort(int inputSize, const char** input)
{
    std::clock_t start, end;

    _size = inputSize;
    start = std::clock();
    makeMainChain(input);
    mergeInsertion();
    end = std::clock();
    _time = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}
