/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:36 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 16:44:25 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void){
    setName("Anonyme");
    setHit(10);
    setEnergy(10);
    setAttack(0);
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : m_name(name) {
    setHit(10);
    setEnergy(10);
    setAttack(0);
    std::cout << "Default constructor called for " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "Copy assignment operator called\n";
    setName(copy.m_name);
    setHit(copy.m_hit);
    setEnergy(copy.m_energy);
    setAttack(copy.m_attack);
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called on " << getName() << "\n";
}

void ClapTrap::setName( std::string name ) {
    m_name = name;
}

void ClapTrap::setHit( unsigned int const amount ) {
    m_hit = amount;
}

void ClapTrap::setEnergy( unsigned int const amount ) {
    m_energy = amount;
}

void ClapTrap::setAttack( unsigned int const amount ) {
    m_attack = amount;
}

std::string ClapTrap::getName( void ) const {
    return m_name;
}

unsigned int ClapTrap::getHit( void ) const {
    return m_hit;
}

unsigned int ClapTrap::getEnergy( void ) const {
    return m_energy;
}

unsigned int ClapTrap::getAttack( void ) const {
    return m_attack;
}

void ClapTrap::attack(const std::string& target) {
    if (getHit() == 0)
    {
        std::cout << getName() << " is already dead, no attack possible!\n";
        return ;
    }
    if (getEnergy() < 1)
    {
        std::cout << getName() << " has no energy left to attack.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << getName() << " attacks " << target \
    << ", causing " << getAttack() << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (getHit() == 0)
    {
        std::cout << getName() << " is already dead, stop it!\n";
        return ;
    }
    if (getHit() < amount)
    {
        setHit(0);
        std::cout << getName() << " died.\n";
        return ;
    }
    setHit(getHit() - amount);
    std::cout << getName() << " took a damage of " << amount << " its health is now " << getHit() << ".\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (getHit() == 0)
    {
        std::cout << getName() << " is already dead, no repair possible!\n";
        return ;
    }
    if (getEnergy() < 1)
    {
        std::cout << getName() << " has no energy left to be repaired.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    setHit(getHit() + amount);
    std::cout << getName() << " is being repaired, its health is now " << getHit() << ".\n";
}
