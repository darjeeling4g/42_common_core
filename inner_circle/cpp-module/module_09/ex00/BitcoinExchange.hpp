/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:48 by siyang            #+#    #+#             */
/*   Updated: 2024/01/31 14:55:45 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <utility>

class BitcoinExchange
{
  public:
    class FileOpenException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Error: could not open file.");
        }
    };
    class NegativeValueException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Error: not a positive number.");
        }
    };
    class BadInputException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Error: bad input => ");
        }

      public:
        BadInputException(std::string detail) : detail(detail)
        {
        }
        ~BadInputException() throw()
        {
        }
        std::string detail;
    };
    class TooLargeException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Error: too large a number.");
        }
    };

    enum eDateFormat
    {
        YYYY = 0,
        FIRSTDELIMITER = 4,
        MM = 5,
        SECONDDELIMITER = 7,
        DD = 8,
        DATESIZE = 10,
    };

  public:
    explicit BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);
    ~BitcoinExchange();
    void setDataBase(const std::string& fileName);
    void exchangeFile(const std::string& inputFile) const;
    void exchange(const std::string& input) const;
    void validateDate(const std::string& date) const;
    int isLeapYear(const int& year) const throw();

  public:
    typedef std::greater<std::string> stringGreater;

  private:
    std::map<std::string, float, stringGreater> dataBase;
};
