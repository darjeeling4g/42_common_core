/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:30:42 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 16:44:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.h"
#include "Grade.h"

class AForm
{
  public:
    AForm(std::string name, Grade gradeForSign, Grade gradeForExecute);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);
    virtual ~AForm() throw();
    const std::string& getName() const throw();
    const Grade& getGradeForSign() const throw();
    const Grade& getGradeForExecute() const throw();
    const bool& getIsSigned() const throw();
    void beSigned(Bureaucrat& bureaucrat);
    // virtual void execute(Bureaucrat const& executor) const = 0;

  public:
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Form Grade is too High");
        }
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Form Grade is too Low");
        }
    };
    class AlreadySignedException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Form is already signed");
        }
    };

  private:
    const std::string _name;
    const Grade _gradeForSign;
    const Grade _gradeForExecute;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& out, AForm& rhs);
