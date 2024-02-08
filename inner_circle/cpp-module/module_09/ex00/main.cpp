/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:09 by siyang            #+#    #+#             */
/*   Updated: 2024/01/31 14:58:37 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    (void)argv;
    try
    {
        if (argc != 2)
        {
            throw BitcoinExchange::FileOpenException();
        }
        BitcoinExchange exchanger;

        exchanger.setDataBase("data.csv");
        exchanger.exchangeFile(argv[1]);
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
