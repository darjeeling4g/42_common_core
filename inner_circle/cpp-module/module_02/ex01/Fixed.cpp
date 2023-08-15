/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:18 by siyang            #+#    #+#             */
/*   Updated: 2023/08/15 15:35:35 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed()
  : rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int numInt)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = numInt << fractionBits;
}

Fixed::Fixed(const float numFloat)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(numFloat * (1 << fractionBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawBits = copy.getRawBits();

    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return (this->rawBits);
}

void Fixed::setRawBits(int const rawBits)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = rawBits;
}

float Fixed::toFloat() const
{
    return ((float)rawBits / (1 << fractionBits));
}

int Fixed:: toInt() const
{
    return (rawBits >> fractionBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNum)
{
    out << fixedNum.toFloat();
    return (out);
}
