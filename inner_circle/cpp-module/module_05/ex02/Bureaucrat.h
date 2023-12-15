/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:29:53 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 16:44:47 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Grade.h"

class AForm;

class Bureaucrat
{
  public:
    Bureaucrat(std::string name, Grade grade);
    Bureaucrat(Bureaucrat& copy);
    Bureaucrat& operator=(Bureaucrat& copy);
    ~Bureaucrat() throw();
    const std::string& getName() const throw();
    const Grade& getGrade() const throw();
    Bureaucrat& increaseGrade();
    Bureaucrat& decreaseGrade();
    Bureaucrat& signForm(AForm& form) throw();

  public:
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Bureaucrat Grade is too HIGH");
        }
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Bureaucrat Grade is too LOW");
        };
    };

  private:
    const std::string _name;
    Grade _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& rhs);
