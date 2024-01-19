/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:16:33 by siyang            #+#    #+#             */
/*   Updated: 2024/01/03 16:46:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <limits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const char* str)
{
    char* strEnd = NULL;
    double raw = std::strtod(str, &strEnd);

    try
    {
        if (str[0] && str[1] == '\0' && !std::isdigit(str[0]))
        {
            raw = static_cast<double>(str[0]);
        }
        if (raw == 0 && strEnd == str)
        {
            throw 1;
        }

        std::cout << "char: ";
        std::numeric_limits<char>::min() <= raw&& raw <= std::numeric_limits<char>::max()
            ? std::isprint(static_cast<unsigned char>(raw)) ? std::cout << static_cast<char>(raw)
                                                            : std::cout << "Non displayable"
            : std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "int: ";
        std::numeric_limits<int>::min() <= raw&& raw <= std::numeric_limits<int>::max()
            ? std::cout << static_cast<int>(raw)
            : std::cout << "impossible";
        std::cout << std::endl;

        std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10);
        std::isnan(static_cast<float>(raw)) || std::isinf(static_cast<float>(raw))
            ? std::cout << std::showpos << static_cast<float>(raw) << std::noshowpos << "f"
        : std::fmod(raw, 1) == 0 ? std::cout << static_cast<float>(raw) << ".0f"
                                 : std::cout << static_cast<float>(raw) << "f";
        std::cout << std::endl;

        std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10);
        std::isnan(static_cast<double>(raw)) || std::isinf(static_cast<double>(raw))
            ? std::cout << std::showpos << static_cast<double>(raw) << std::noshowpos
        : std::fmod(raw, 1) == 0 ? std::cout << static_cast<double>(raw) << ".0"
                                 : std::cout << static_cast<double>(raw);
        std::cout << std::endl;
    }
    catch (int expn)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible" << std::endl;
    }
}
