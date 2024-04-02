/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:32:47 by siyang            #+#    #+#             */
/*   Updated: 2024/03/08 16:27:11 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(const int argc, const char* argv[])
{
    try
    {
        PmergeMe<intVectorType> vecPmergeMe;
        PmergeMe<intListType> lstPmergeMe;
        if (argc < 2)
        {
            throw std::runtime_error("Error: too few arguments");
        }

        vecPmergeMe.sort(argc - 1, argv + 1);
        lstPmergeMe.sort(argc - 1, argv + 1);

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
        {
            std::cout << " " << argv[i];
        }
        std::cout << std::endl;
        std::cout << "After:  " << vecPmergeMe << std::endl;
        std::cout << "Time to process a range of "
                  << "elements with std::vector : " << std::showpoint << vecPmergeMe.getTime() << std::noshowpoint
                  << " us" << std::endl;
        std::cout << "Time to process a range of "
                  << "elements with std::list   : " << std::showpoint << lstPmergeMe.getTime() << std::noshowpoint
                  << " us" << std::endl;
    }
    catch (const std::exception& expn)
    {
        std::cerr << expn.what() << std::endl;
    }
}
