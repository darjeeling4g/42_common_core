/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:27:42 by siyang            #+#    #+#             */
/*   Updated: 2024/01/05 16:51:19 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    iter(arr, 5, print);
    std::cout << std::endl;
    iter(arr, 5, clear);
    iter(arr, 5, print);
    std::cout << std::endl;

    char str[12] = "test string";
    iter(str, 12, print);
    std::cout << std::endl;
    iter(str, 12, clear);
    iter(str, 12, print);
    std::cout << std::endl;
}
