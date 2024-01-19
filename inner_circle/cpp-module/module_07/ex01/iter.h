/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:27:44 by siyang            #+#    #+#             */
/*   Updated: 2024/01/05 16:56:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> void iter(T arr[], int len, void (*func)(T& arg))
{
    for (int i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template <typename T> void print(T& arg)
{
    std::cout << arg;
}

template <typename T> void clear(T& arg)
{
    arg = 0;
}
