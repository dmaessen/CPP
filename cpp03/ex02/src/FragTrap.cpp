/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:19:49 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:24 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHit(100);
	setEnergy(100);
	setAttack(30);
	std::cout << "FragTrap default constructor called for " << getName() << "\n";
}

FragTrap::FragTrap(const FragTrap &copy) {
    std::cout << "FragTrap copy constructor called\n";
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &copy) {
    std::cout << "FragTrap copy assignment operator called\n";
    setName(copy.getName());
    setHit(copy.getHit());
    setEnergy(copy.getEnergy());
    setAttack(copy.getAttack());
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called on " << getName() << "\n";
}

void FragTrap::highFivesGuys(void) {
    if (getHit() == 0)
    {
        std::cout << "FragTrap " << getName() << " is technically dead so its hard\
 to give a high five in those circumstances, i guess...\n";
        return ;
    }
	std::cout << "FragTrap " << getName() << "'s high fives request was positive.\n";
}

void FragTrap::attack(const std::string& target) {
    if (getHit() == 0)
    {
        std::cout << "FragTrap " << getName() << " is already dead, no attack possible!\n";
        return ;
    }
    if (getEnergy() < 1)
    {
        std::cout << "FragTrap " << getName() << " has no energy left to attack.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << "FragTrap " << getName() << " attacks " << target \
    << ", causing " << getAttack() << " points of damage!\n";
}
