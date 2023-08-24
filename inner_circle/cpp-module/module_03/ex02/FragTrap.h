/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:33:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 12:58:07 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE03_EX02_FRAGTRAP_H_
#define MODULE03_EX02_FRAGTRAP_H_

#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    virtual ~FragTrap();
    void highFivesGuys(void);

private:
};

#endif
