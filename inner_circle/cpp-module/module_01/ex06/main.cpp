/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:38:09 by siyang            #+#    #+#             */
/*   Updated: 2023/08/01 15:29:06 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int argc, char *argv[])
{
    Harl harl;

    if (argc != 2)
        return (1);
    harl.complain(argv[1]);
    return (0);
}
