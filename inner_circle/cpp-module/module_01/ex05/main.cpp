/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:38:09 by siyang            #+#    #+#             */
/*   Updated: 2023/08/01 14:53:40 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(void)
{
    Harl harl;

    harl.complain("DEBUG"); 
    harl.complain("INFO"); 
    harl.complain("WARNING"); 
    harl.complain("ERROR"); 
    return (0);
}
