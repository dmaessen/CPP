/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:54:04 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/14 14:29:18 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
    std::cout << "constructor called\n";
}

Zombie::~Zombie(void){
    std::cout << "destructor called on " << getName() << '\n';
}

void    Zombie::setName(std::string input){
    m_name = input;
}

std::string Zombie::getName() const{
    return m_name;
}

void    Zombie::announce(void){
    std::string name = getName();
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
