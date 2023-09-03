/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:29:41 by siyang            #+#    #+#             */
/*   Updated: 2023/08/31 14:44:53 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE04_EX01_BRAIN_H_
#define MODULE04_EX01_BRAIN_H_

#include <iostream>
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    ~Brain();
    Brain& setFirstIdea(std::string idea);
    void printFirstIdea() const;

private:
    std::string ideas[100];
};

#endif
