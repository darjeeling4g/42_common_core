/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:55:44 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 22:07:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX00_WRONGCAT_H_
#define MODULE04_EX00_WRONGCAT_H_

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& copy);
    WrongCat& operator=(const WrongCat& copy);
    ~WrongCat();
    void makeSound() const;
};

#endif
