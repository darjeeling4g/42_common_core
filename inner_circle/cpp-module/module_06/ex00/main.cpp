/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:20:21 by siyang            #+#    #+#             */
/*   Updated: 2024/01/03 11:50:24 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <exception>
#include <ios>
#include <stdexcept>

#include <iomanip>

int main(int argc, char** argv)
{
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("wrong number of arguments");
        }
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
