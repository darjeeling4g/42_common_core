/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:04:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:59:15 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

void CheckLeaks()
{
    system("leaks brain");
}

int main()
{
    atexit(CheckLeaks);
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << "==============================" << std::endl;

    const Animal* animal[10];
    for (int i = 0; i < 6; i++) 
    {
        if (i % 2 == 0)
        {
            animal[i] = new Cat();
        }
        else
        {
            animal[i] = new Dog();
        }
    }
    for (int i = 0; i < 6; i++)
    {
        delete animal[i];
    }

    std::cout << "==============================" << std::endl;

    Cat cat;
    cat.getBrain()->printFirstIdea();
    cat.getBrain()->setFirstIdea("eat lunch").printFirstIdea();
    std::cout << std::endl;
    Cat duplicant(cat);
    duplicant.getBrain()->printFirstIdea();
    duplicant.getBrain()->setFirstIdea("napping").printFirstIdea();
    std::cout << std::endl;
    Cat duplicant2;
    duplicant2 = duplicant;
    duplicant2.getBrain()->printFirstIdea();
    std::cout << std::endl;
    return 0;
}
