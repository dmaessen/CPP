/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:46 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/16 13:51:11 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    m_name = name;
    m_weapon = nullptr;
    std::cout << "HumanB constructor called\n";
}

HumanB::~HumanB(){
    std::cout << "HumanB destructor called\n";
}

void HumanB::setName(std::string input) {
    m_name = input;
}

void HumanB::setWeapon(Weapon& w) {
    m_weapon = &w;
}

std::string HumanB::getName() const {
    return m_name;
}

Weapon HumanB::getWeapon() const {
    return *m_weapon;
}

void    HumanB::attack() {
    if (m_weapon == nullptr)
        std::cout << m_name << " attacks" << '\n';
    else
        std::cout << m_name << " attacks with their " << m_weapon->getType() << '\n';
}

// reference for HumanA, as it needs a weapon either way, and will be used once
// using a pointer for HumanB (if we don't we couldn't assign it to NULL if we don't have a weapon)