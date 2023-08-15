/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:31 by siyang            #+#    #+#             */
/*   Updated: 2023/08/15 20:54:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE02_EX00_FIXED_H_
#define MODULE02_EX00_FIXED_H_


#include <iostream>
#include <cmath>

class Fixed
{

public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& copy);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const rawBits);

private:
    static const int fractionBits = 8;
    int rawBits;

};

#endif
