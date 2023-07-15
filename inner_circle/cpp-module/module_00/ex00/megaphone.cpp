/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:22:01 by siyang            #+#    #+#             */
/*   Updated: 2023/07/15 20:34:01 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::toupper;

void PrintUpperString(string str)
{
  for (size_t i = 0; i < str.size(); i++)
  {
    str[i] = toupper(str[i]);
  }
  cout << str;
}

int main(int argc, char **argv)
{

  if (argc == 1)
  {
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
  }
  else 
  {
    for (ssize_t i = 1; i < argc; i++)
    {
      PrintUpperString(argv[i]);
    }
    cout << endl;
  }
  return (0);
}
