/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:47 by siyang            #+#    #+#             */
/*   Updated: 2023/12/20 14:50:40 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern
{
  public:
    Intern();
    Intern(const Intern& copy);
    Intern& operator=(const Intern& copy);
    ~Intern();
    AForm* makeForm(std::string type, std::string name);

  public:
    class NoFormTypeException : public std::exception
    {
      public:
        virtual const char* what() const throw()
        {
            return ("Form type doesn't exist");
        }
    };

  private:
    enum eFormType
    {
        SHRUBBERY,
        ROBOTOMY,
        PARDON,
    };
};
