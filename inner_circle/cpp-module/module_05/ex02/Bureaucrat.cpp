/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:50 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 17:18:08 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"

Bureaucrat::Bureaucrat(std::string name, Grade grade) : _name(name), _grade(grade)
{
    if (grade > Grade(1))
    {
        throw GradeTooHighException();
    }
    else if (grade < Grade(150))
    {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& copy)
{
    if (this != &copy)
    {
        if (copy._grade > Grade(1))
        {
            throw GradeTooHighException();
        }
        else if (copy._grade < Grade(150))
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

const Grade& Bureaucrat::getGrade() const throw()
{
    return (_grade);
}

Bureaucrat& Bureaucrat::increaseGrade()
{
    _grade++;
    if (_grade > Grade(1))
    {
        throw GradeTooHighException();
    }
    return (*this);
}

Bureaucrat& Bureaucrat::decreaseGrade()
{
    _grade--;
    if (_grade < Grade(150))
    {
        throw GradeTooLowException();
    }
    return (*this);
}

Bureaucrat& Bureaucrat::signForm(AForm& form) throw()
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& rhs)
{
    out << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return (out);
}
