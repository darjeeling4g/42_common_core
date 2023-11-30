/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:30:42 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 16:56:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.h"

class Form
{
  public:
    Form(std::string name, int gradeForSign, int gradeForExecute);
    Form(Form& copy);
    Form& operator=(Form& copy);
    ~Form() throw();
    const std::string& getName() const throw();
    const int& getGradeForSign() const throw();
    const int& getGradeForExecute() const throw();
    const bool& getIsSigned() const throw();
    void beSigned(Bureaucrat& bureaucrat);

  public:
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("exception: Grade is too High");
        }
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("exception: Grade is too Low");
        }
    };

  private:
    const std::string _name;
    const int _gradeForSign;
    const int _gradeForExecute;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& out, Form& rhs);
