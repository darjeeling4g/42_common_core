/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:54 by siyang            #+#    #+#             */
/*   Updated: 2023/12/13 17:17:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Grade
{
  public:
    explicit Grade(const int grade);
    Grade(const Grade& copy);
    Grade& operator=(const Grade& copy);
    bool operator==(const Grade& rhs) const throw();
    bool operator!=(const Grade& rhs) const throw();
    bool operator>(const Grade& rhs) const throw();
    bool operator<(const Grade& rhs) const throw();
    bool operator>=(const Grade& rhs) const throw();
    bool operator<=(const Grade& rhs) const throw();
    Grade operator++(int);
    Grade operator--(int);
    int getGrade() const throw();
    ~Grade();

  private:
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Grade& rhs);
