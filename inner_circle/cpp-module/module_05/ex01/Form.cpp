/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:30:39 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 17:14:55 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

Form::Form(std::string name, int gradeForSign, int gradeForExecute)
    : _name(name), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute), _isSigned(false)
{
    if (gradeForSign < 1 || gradeForExecute < 1)
    {
        throw GradeTooHighException();
    }
    else if (gradeForSign > 150 || gradeForExecute > 150)
    {
        throw GradeTooLowException();
    }
}

Form::Form(Form& copy) : _name(copy._name), _gradeForSign(copy._gradeForSign), _gradeForExecute(copy._gradeForExecute)
{
    *this = copy;
}

Form& Form::operator=(Form& copy)
{
    if (this != &copy)
    {
        if (copy._gradeForSign < 1 || copy._gradeForExecute < 1)
        {
            throw GradeTooHighException();
        }
        else if (copy._gradeForSign > 150 || copy._gradeForExecute > 150)
        {
            throw GradeTooLowException();
        }
        this->_isSigned = copy._isSigned;
    }
    return (*this);
}

Form::~Form() throw()
{
}

const std::string& Form::getName() const throw()
{
    return (_name);
}

const int& Form::getGradeForSign() const throw()
{
    return (_gradeForSign);
}

const int& Form::getGradeForExecute() const throw()
{
    return (_gradeForExecute);
}

const bool& Form::getIsSigned() const throw()
{
    return (_isSigned);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (_gradeForSign > bureaucrat.getGrade())
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& out, Form& rhs)
{
    std::cout << "[Form] Name --> '" << rhs.getName() << "' | ";
    std::cout << "Grade for sign --> '" << rhs.getGradeForSign() << "' | ";
    std::cout << "Grade for execute --> '" << rhs.getGradeForExecute() << "' | ";
    std::cout << "Is signed --> '" << (rhs.getIsSigned() ? "true'" : "false'") << std::endl;
    return (out);
}
