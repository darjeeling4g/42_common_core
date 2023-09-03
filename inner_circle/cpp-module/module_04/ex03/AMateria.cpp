/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:20:16 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 16:37:42 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria(std::string const & type)
  : type(type) {}

std::string const & AMateria::getType() const
{
    return (type);
}
