/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:59:25 by siyang            #+#    #+#             */
/*   Updated: 2023/12/19 16:42:04 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.h"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
    virtual ~ShrubberyCreationForm() throw();
    virtual void execute(Bureaucrat const& executor) const;
};
