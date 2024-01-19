/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:03:49 by siyang            #+#    #+#             */
/*   Updated: 2024/01/16 20:53:04 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>

template <typename T> typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);

    if (iter == container.end())
    {
        throw std::runtime_error("No elements in container");
    }
    return (iter);
}
