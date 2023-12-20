/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:58:52 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 16:42:10 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.h"

#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    virtual ~RobotomyRequestForm() throw();
    virtual void execute(Bureaucrat const& executor) const;
};
