/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:32:42 by siyang            #+#    #+#             */
/*   Updated: 2024/03/08 16:11:27 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <> void PmergeMe<intVectorType>::mergeInsertion()
{
    // _container.reserve(_size);
    _container.push_back(_mainChain[0].second);
    for (std::vector<intPairType>::iterator iter = _mainChain.begin(); iter != _mainChain.end(); iter++)
    {
        if (iter->first != -1)
        {
            _container.push_back(iter->first);
        }
    }
    for (std::size_t i = 2; i <= _mainChain.size(); i++)
    {
        if (i > _jacobsthalNum)
        {
            updateJacobsthalNum();
        }
        recursion(i, _mainChain[i - 1].second);
    }
}

template <> void PmergeMe<intListType>::mergeInsertion()
{
    _container.push_back(_mainChain[0].second);
    for (std::vector<intPairType>::iterator iter = _mainChain.begin(); iter != _mainChain.end(); iter++)
    {
        if (iter->first != -1)
        {
            _container.push_back(iter->first);
        }
    }
    for (std::size_t i = 2; i <= _mainChain.size(); i++)
    {
        if (i > _jacobsthalNum)
        {
            updateJacobsthalNum();
        }
        recursion(i, _mainChain[i - 1].second);
    }
}
