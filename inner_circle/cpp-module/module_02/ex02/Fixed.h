/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:31 by siyang            #+#    #+#             */
/*   Updated: 2023/08/15 20:45:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE02_EX02_FIXED_H_
#define MODULE02_EX02_FIXED_H_


#include <iostream>
#include <cmath>

class Fixed
{

public:
    Fixed();
    Fixed(const int numInt);
    Fixed(const float numFloat);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;
    Fixed& operator++(void);
    const Fixed operator++(int);
    Fixed& operator--(void);
    const Fixed operator--(int);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const rawBits);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int rawBits;

public:
    static Fixed& min(Fixed& lhs, Fixed& rhs);
    const static Fixed& min(const Fixed& lhs, const Fixed& rhs);
    static Fixed& max(Fixed& lhs, Fixed&rhs);
    const static Fixed& max(const Fixed& lhs, const Fixed& rhs);

private:
    static const int fractionBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNum);

#endif
