/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:30:39 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 15:17:37 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm(std::string name, Grade gradeForSign, Grade gradeForExecute)
    : _name(name), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute), _isSigned(false)
{
    if (gradeForSign > Grade(1) || gradeForExecute > Grade(1))
    {
        throw GradeTooHighException();
    }
    else if (gradeForSign < Grade(150) || gradeForExecute < Grade(150))
    {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& copy)
    : _name(copy._name), _gradeForSign(copy._gradeForSign), _gradeForExecute(copy._gradeForExecute)
{
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy)
    {
        if (copy._gradeForSign > Grade(1) || copy._gradeForExecute > Grade(1))
        {
            throw GradeTooHighException();
        }
        else if (copy._gradeForSign < Grade(150) || copy._gradeForExecute < Grade(150))
        {
            throw GradeTooLowException();
        }
        this->_isSigned = copy._isSigned;
    }
    return (*this);
}

AForm::~AForm() throw()
{
}

const std::string& AForm::getName() const throw()
{
    return (_name);
}

const Grade& AForm::getGradeForSign() const throw()
{
    return (_gradeForSign);
}

const Grade& AForm::getGradeForExecute() const throw()
{
    return (_gradeForExecute);
}

const bool& AForm::getIsSigned() const throw()
{
    return (_isSigned);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (this->_gradeForSign > bureaucrat.getGrade())
    {
        throw GradeTooLowException();
    }
    else if (_isSigned == true)
    {
        throw AlreadySignedException();
    }
    _isSigned = true;
}

void AForm::checkExecutable(Bureaucrat const& executor) const
{
    if (this->_isSigned == false)
    {
        throw SignRequiredException();
    }
    else if (executor.getGrade() < this->_gradeForExecute)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, AForm& rhs)
{
    out << "[Form] Name --> '" << rhs.getName() << "' | ";
    out << "Grade for sign --> '" << rhs.getGradeForSign() << "' | ";
    out << "Grade for execute --> '" << rhs.getGradeForExecute() << "' | ";
    out << "Is signed --> '" << (rhs.getIsSigned() ? "true'" : "false'") << std::endl;
    return (out);
}
