/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:13:14 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 17:04:53 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grade.h"

Grade::Grade(const int grade) : _grade(grade)
{
}

Grade::Grade(const Grade& copy) : _grade(copy._grade)
{
}

Grade& Grade::operator=(const Grade& copy)
{
    if (this != &copy)
    {
        _grade = copy._grade;
    }
    return (*this);
}

bool Grade::operator==(const Grade& rhs) const throw()
{
    return (this->_grade == rhs._grade ? true : false);
}

bool Grade::operator!=(const Grade& rhs) const throw()
{
    return (this->_grade != rhs._grade ? true : false);
}

bool Grade::operator>(const Grade& rhs) const throw()
{
    return (this->_grade < rhs._grade ? true : false);
}

bool Grade::operator<(const Grade& rhs) const throw()
{
    return (this->_grade > rhs._grade ? true : false);
}

bool Grade::operator>=(const Grade& rhs) const throw()
{
    return (this->_grade <= rhs._grade ? true : false);
}

bool Grade::operator<=(const Grade& rhs) const throw()
{
    return (this->_grade >= rhs._grade ? true : false);
}

Grade Grade::operator++(int)
{
    Grade tmp = *this;

    _grade -= 1;
    return (tmp);
}

Grade Grade::operator--(int)
{
    Grade tmp = *this;

    _grade += 1;
    return (tmp);
}

int Grade::getGrade() const throw()
{
    return (_grade);
}

Grade::~Grade()
{
}

std::ostream& operator<<(std::ostream& out, const Grade& rhs)
{
    out << rhs.getGrade();
    return (out);
}
