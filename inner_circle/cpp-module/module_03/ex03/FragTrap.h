/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:33:00 by siyang            #+#    #+#             */
/*   Updated: 2023/08/24 15:55:15 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE03_EX02_FRAGTRAP_H_
#define MODULE03_EX02_FRAGTRAP_H_

#include "ClapTrap.h"

#define FRAG_HIT (100)
#define FRAG_ENERGY (100)
#define FRAG_DAMAGE (30)

class FragTrap : virtual public ClapTrap
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
