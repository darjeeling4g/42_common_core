/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:24:15 by siyang            #+#    #+#             */
/*   Updated: 2023/08/01 16:20:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string line;

    if (argc != 4)
    {
        std::cerr << "Error: arguments must have 'filename', 's1', 's2'\n";
        return (1);
    }
    std::ifstream infile(argv[1]);
    if (infile.is_open() == false)
    {
        std::cerr << "Error: " << argv[1] << " doesn't exist\n";
        return (1);
    }
    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (outfile.is_open() == false)
    {
        std::cerr << "Error: fail to create '.replace' file\n";
        return (1);
    }
    while (infile.eof() == false)
    {
        getline(infile, line);
        std::string::size_type pos(line.find(argv[2]));
        if (pos != std::string::npos)
        {
            line.erase(pos, std::string(argv[2]).length());
            line.insert(pos, argv[3]);
        }
        outfile << line << '\n';
    }
    return (0);
}
