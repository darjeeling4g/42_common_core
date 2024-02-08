/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:15 by siyang            #+#    #+#             */
/*   Updated: 2024/02/08 22:31:32 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

void RPN::calculate(const std::string& input)
{
    int lhs, rhs;
    for (std::string::const_iterator iter = input.begin(); iter != input.end(); iter++)
    {
        if (std::isdigit(*iter))
        {
            this->push(std::atoi(&(*iter)));
        }
        else if (std::isspace(*iter))
        {
        }
        else
        {
            if (this->size() < 2)
            {
                throw std::runtime_error("Error");
            }
            rhs = this->top();
            this->pop();
            lhs = this->top();
            this->pop();
            switch (*iter)
            {
            case PLUS:
                this->push(lhs + rhs);
                break;
            case SUBTRACT:
                this->push(lhs - rhs);
                break;
            case DIVIDE:
                if (rhs == 0)
                {
                    throw std::runtime_error("Divide by zero");
                }
                this->push(lhs / rhs);
                break;
            case MULTIPLY:
                this->push(lhs * rhs);
                break;
            default:
                throw std::runtime_error("Error");
                break;
            }
        }
    }
}
