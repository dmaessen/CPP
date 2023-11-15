/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:53:09 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:31 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(){
    std::cout << "Weapon destructor called\n";
    // needed??
}

Weapon::Weapon(std::string input) {
    m_type = input;
    std::cout << "Weapon destructor called\n";
}

Weapon::~Weapon(){
    std::cout << "Weapon destructor called\n";
}

void Weapon::setType(std::string input) {
    m_type = input;
}

std::string Weapon::getType() const {
    return m_type;
}
