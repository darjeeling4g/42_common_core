/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:18 by siyang            #+#    #+#             */
/*   Updated: 2023/08/15 17:53:54 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed()
  : rawBits(0) {}

Fixed::Fixed(const int numInt)
{
    rawBits = numInt << fractionBits;
}

Fixed::Fixed(const float numFloat)
{
    rawBits = roundf(numFloat * (1 << fractionBits));
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    this->rawBits = copy.getRawBits();

    return (*this);
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return (this->rawBits > rhs.rawBits);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return (this->rawBits < rhs.rawBits);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return (this->rawBits >= rhs.rawBits);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return (this->rawBits <= rhs.rawBits);
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return (this->rawBits == rhs.rawBits);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return (this->rawBits != rhs.rawBits);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed tmp(this->toFloat() + rhs.toFloat());
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed tmp(this->toFloat() - rhs.toFloat());
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed tmp(this->toFloat() * rhs.toFloat());
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed tmp(this->toFloat() / rhs.toFloat());
    return (tmp);
}

Fixed& Fixed::operator++()
{
    this->rawBits++;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->rawBits++;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    this->rawBits--;
    return (*this);
}

const Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->rawBits--;
    return (tmp);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return (this->rawBits);
}

void Fixed::setRawBits(int const rawBits)
{
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

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    return (lhs > rhs ? lhs : rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs > rhs ? lhs : rhs);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNum)
{
    out << fixedNum.toFloat();
    return (out);
}

