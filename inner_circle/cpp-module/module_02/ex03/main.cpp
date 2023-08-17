/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:39:13 by siyang            #+#    #+#             */
/*   Updated: 2023/08/17 15:00:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

int main( void )
{
    std::cout << "[ Point is inside the triangle ]\n";
    std::cout << "P1 = ";
    std::cout << bsp(Point(-5.2f, 4.2f), Point(3.4f, 2.0f), Point(-1.6f, -2.8f), Point(-1.4f, 1.4f)) << std::endl;
    std::cout << "P3 = ";
    std::cout << bsp(Point(-5.2f, 4.2f), Point(3.4f, 2.0f), Point(-1.6f, -2.8f), Point(1.6f, 0.4f)) << std::endl;
    std::cout << "[ Point is outside the triangle ]\n";
    std::cout << "P2 = ";
    std::cout << bsp(Point(-5.2f, 4.2f), Point(3.4f, 2.0f), Point(-1.6f, -2.8f), Point(2.0f, 3.8f)) << std::endl;
    std::cout << "P4 = ";
    std::cout << bsp(Point(-5.2f, 4.2f), Point(3.4f, 2.0f), Point(-1.6f, -2.8f), Point(5.0f, 2.0f)) << std::endl;
    return (0);
}
