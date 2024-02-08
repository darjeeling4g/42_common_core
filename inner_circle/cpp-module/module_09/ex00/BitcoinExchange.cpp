/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:58 by siyang            #+#    #+#             */
/*   Updated: 2024/01/31 15:06:18 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
    if (this != &copy)
    {
        this->dataBase = copy.dataBase;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::setDataBase(const std::string& fileName)
{
    std::string strBuf;
    std::ifstream csv(fileName);
    if (csv.fail())
    {
        throw FileOpenException();
    }
    csv >> strBuf;
    if (strBuf != "date,exchange_rate")
    {
        throw BadInputException(strBuf);
    }
    while (true)
    {
        csv >> strBuf;
        std::string::size_type comma = strBuf.find(",");
        if (comma == std::string::npos || comma != strBuf.rfind(","))
        {
            throw BadInputException(strBuf);
        }
        if (csv.eof())
        {
            break;
        }
        validateDate(strBuf.substr(0, comma));
        dataBase.insert(std::make_pair<std::string, float>(strBuf.substr(0, comma),
                                                           std::strtod(strBuf.substr(comma + 1).c_str(), NULL)));
    }

    // @파싱 값 출력
    // for (std::map<std::string, float>::iterator iter = dataBase.begin(); iter != dataBase.end(); iter++)
    // {
    //     std::cout << iter->first << " " << iter->second << std::endl;
    // }
}

void BitcoinExchange::exchangeFile(const std::string& inputFile) const
{
    // check valid file
    std::ifstream file(inputFile);
    if (file.fail())
    {
        throw BitcoinExchange::FileOpenException();
    }

    // check first line format
    std::string strBuf;
    std::getline(file, strBuf);
    if (strBuf != "date | value")
    {
        throw BadInputException(strBuf);
    }

    // loop
    while (true)
    {
        std::getline(file, strBuf);
        if (file.eof())
        {
            break;
        }
        try
        {
            exchange(strBuf);
        }
        catch (const BitcoinExchange::BadInputException& expn)
        {
            std::cerr << expn.what() << expn.detail << std::endl;
        }
        catch (const std::exception& expn)
        {
            std::cerr << expn.what() << std::endl;
        }
    }
}

void BitcoinExchange::exchange(const std::string& input) const
{
    std::string::size_type delim = input.find(" | ");
    if (delim == std::string::npos || delim != input.rfind(" | "))
    {
        throw BadInputException(input);
    }

    std::string date = input.substr(0, delim);
    validateDate(date);

    char* strEnd;
    float value = std::strtod(input.substr(delim + 3).c_str(), &strEnd);
    if (*strEnd != '\0')
    {
        throw BadInputException(input.substr(delim + 3));
    }
    else if (value < 0)
    {
        throw NegativeValueException();
    }
    else if (value > 1000)
    {
        throw TooLargeException();
    }
    std::cout << date << " => " << value << " = " << value * dataBase.lower_bound(date)->second << std::endl;
}

void BitcoinExchange::validateDate(const std::string& date) const
{
    if (date.size() != DATESIZE)
    {
        throw BadInputException(date);
    }

    std::string::const_iterator iter = date.begin();
    int year, month, day, daysInMonth;
    for (int i = 0; i < DATESIZE; i++)
    {
        switch (i)
        {
        case YYYY:
            year = std::strtod(date.substr(YYYY, FIRSTDELIMITER).c_str(), NULL);
            if (year < 0 || year > 9999)
            {
                throw BadInputException(date);
            }
            break;

        case MM:
            month = std::strtod(date.substr(MM, SECONDDELIMITER).c_str(), NULL);
            if (month < 1 || month > 12)
            {
                throw BadInputException(date);
            }
            break;

        case DD:
            day = std::strtod(date.substr(DD).c_str(), NULL);
            daysInMonth = 31 - ((month == 2) ? (3 - isLeapYear(year)) : ((month - 1) % 7 % 2));
            if (day < 1 || day > daysInMonth)
            {
                throw BadInputException(date);
            }
            break;

        case FIRSTDELIMITER:
        case SECONDDELIMITER:
            if (*(iter + i) != '-')
            {
                throw BadInputException(date);
            }
            break;

        default:
            if (!std::isdigit(*(iter + i)))
            {
                throw BadInputException(date);
            }
            break;
        }
    }
}

int BitcoinExchange::isLeapYear(const int& year) const throw()
{
    return (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0) ? 0 : 1);
}
