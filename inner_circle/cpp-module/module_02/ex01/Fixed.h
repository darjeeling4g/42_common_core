/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:31 by siyang            #+#    #+#             */
/*   Updated: 2023/08/15 20:44:43 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE02_EX01_FIXED_H_
#define MODULE02_EX01_FIXED_H_

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
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const rawBits);
    float toFloat(void) const;
    int toInt(void) const;

private:
    static const int fractionBits = 8;
    int rawBits;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNum);

#endif
