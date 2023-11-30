/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:29:53 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 12:57:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
  public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat& copy);
    Bureaucrat& operator=(Bureaucrat& copy);
    ~Bureaucrat() throw();
    const std::string& getName() const throw();
    const int& getGrade() const throw();
    Bureaucrat& increaseGrade();
    Bureaucrat& decreaseGrade();

  public:
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("exception: Grade is too HIGH");
        }
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("exception: Grade is too LOW");
        };
    };

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& rhs);
