/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:46 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 16:42:12 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
    virtual ~PresidentialPardonForm() throw();
    virtual void execute(Bureaucrat const& executor) const;
};
