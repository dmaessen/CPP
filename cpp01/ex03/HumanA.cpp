/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:50 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/16 13:59:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon& w) : m_name(name), m_weapon(w) {
    std::cout << "HumanA constructor called\n";
}

HumanA::~HumanA(){
    std::cout << "HumanA destructor called\n";
}

void HumanA::setName(std::string input) {
    m_name = input;
}


std::string HumanA::getName() const {
    return m_name;
}

void    HumanA::attack() {
    std::cout << m_name << " attacks with their " << m_weapon.getType() << '\n';
}

// reference for HumanA, as it needs a weapon either way, and will be used once
// using a pointer for HumanB (if we don't we couldn't assign it to NULL if we don't have a weapon)