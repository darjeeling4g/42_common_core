/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:50 by siyang            #+#    #+#             */
/*   Updated: 2023/11/30 16:22:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy._name)
{
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& copy)
{
    if (this != &copy)
    {
        if (copy._grade < 1)
        {
            throw GradeTooHighException();
        }
        else if (copy._grade > 150)
        {
            throw GradeTooLowException();
        }
        _grade = copy._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() throw()
{
}

const std::string& Bureaucrat::getName() const throw()
{
    return (_name);
}

const int& Bureaucrat::getGrade() const throw()
{
    return (_grade);
}

Bureaucrat& Bureaucrat::increaseGrade()
{
    _grade--;
    if (_grade < 1)
    {
        throw GradeTooHighException();
    }
    return (*this);
}

Bureaucrat& Bureaucrat::decreaseGrade()
{
    _grade++;
    if (_grade > 150)
    {
        throw GradeTooLowException();
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& rhs)
{
    std::cout << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return (out);
}
