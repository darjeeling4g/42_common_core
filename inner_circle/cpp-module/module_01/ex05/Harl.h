/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:36:54 by siyang            #+#    #+#             */
/*   Updated: 2023/07/28 17:31:24 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE01_EX05_HARL_H_
#define MODULE01_EX05_HARL_H_

#include <iostream>
#include <string>

enum
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

class Harl
{

public:
    Harl();
    ~Harl();
    void complain( std::string level );

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    void (Harl::*funcPointer[4])(void);
};

#endif // !MODULE01_EX05_HARL_H_
