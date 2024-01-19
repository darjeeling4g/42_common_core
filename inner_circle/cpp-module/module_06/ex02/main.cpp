/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:14:37 by siyang            #+#    #+#             */
/*   Updated: 2024/01/05 13:21:59 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.h"
#include "B.h"
#include "C.h"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <typeinfo>

Base* generate(void)
{
    switch (std::rand() % 3)
    {
    case 0:
        return (new A);
    case 1:
        return (new B);
    case 2:
        return (new C);
    default:
        return (NULL);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "Actual type : A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "Actual type : B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "Actual type : C" << std::endl;
    }
    else
    {
        std::cout << "Actual type : Base" << std::endl;
    }
    delete p;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Actual type : A" << std::endl;
    }
    catch (std::bad_cast)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "Actual type : B" << std::endl;
        }
        catch (std::bad_cast)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "Actual type : C" << std::endl;
            }
            catch (std::bad_cast)
            {
                std::cout << "Actual type : Base" << std::endl;
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));

    std::cout << "Pointer test" << std::endl;
    identify(generate());
    identify(generate());
    identify(generate());
    identify(generate());
    identify(generate());

    std::cout << std::endl;

    std::cout << "Reference test" << std::endl;
    Base* p = generate();
    identify(*p);
    delete p;
    p = generate();
    identify(*p);
    delete p;
    p = generate();
    identify(*p);
    delete p;
    p = generate();
    identify(*p);
    delete p;
    p = generate();
    identify(*p);
    delete p;
}
