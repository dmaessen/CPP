/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:50 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 16:02:43 by dmaessen         ###   ########.fr       */
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

void HumanA::setWeapon(std::string input) {
    m_weapon = input;
}

std::string HumanA::getName() const {
    return m_name;
}

// std::string HumanA::getWeapon() const {
//     return m_weapon;
// }

void    HumanA::attack() {
    std::cout << getName << " attacks with their " <<  << '\n';
}

// referenc e for HumanA, as it needs a weapon eithr way, and will be used once
//using a pointer for HumanB (if we don't we couldn't assign it to NULL if we don't have a weapon)