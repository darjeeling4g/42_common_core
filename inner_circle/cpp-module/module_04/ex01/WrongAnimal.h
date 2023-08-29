/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:00:42 by siyang            #+#    #+#             */
/*   Updated: 2023/08/29 22:07:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX00_WRONGANIMAL_H_
#define MODULE04_EX00_WRONGANIMAL_H_

#include <iostream>
#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& copy);
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;

protected:
    WrongAnimal& setType(std::string type);
    std::string type;
};

#endif // !MODULE04_EX00_ANIMAL_H_
