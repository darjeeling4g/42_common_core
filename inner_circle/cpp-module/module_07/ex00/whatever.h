/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:51:59 by siyang            #+#    #+#             */
/*   Updated: 2024/01/05 16:55:47 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template <typename T> T min(T& lhs, T& rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

template <typename T> T max(T lhs, T rhs)
{
    return (lhs > rhs ? lhs : rhs);
}
