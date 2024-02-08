/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:22 by siyang            #+#    #+#             */
/*   Updated: 2024/01/31 17:05:29 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN : public std::stack<int>
{
  public:
    enum eOperator
    {
        PLUS = 43,
        SUBTRACT = 45,
        DIVIDE = 47,
        MULTIPLY = 42,
    };

  public:
    RPN();
    ~RPN();
    void calculate(const std::string& input);

  private:
    RPN(const RPN& copy);
    RPN& operator=(const RPN& copy);
};
