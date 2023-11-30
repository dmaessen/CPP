/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:36 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/30 15:52:45 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) {
    m_name = name;
    setHit(10);
    setEnergy(10);
    setAttack(0);
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy; // is this right??
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
    std::cout << "Destructor called\n";
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
    if (getEnergy() < 1)
    {
        std::cout << "ClapTrap " << getName() << " has no energy left to attack.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << "ClapTrap " << getName() << " attacks " << target \
    << ", causing " << getAttack() << " points of damage!\n";
    // whats happening to attack ?? we give it a random thing or waht??
    // so we have two claptraps and thus here we might need to call TakeDamage on the given target as param for that one to take the damage
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (getHit() < amount)
    {
        std::cout << "ClapTrap " << getName() << " cannot take this damage anymore, its health is too low.\n";
        return ;
    }
    setHit(getHit() - amount);
    std::cout << "ClapTrap " << getName() << " took a damage of " << amount << " its health is now " << getHit() << ".\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (getEnergy() < 1)
    {
        std::cout << "ClapTrap " << getName() << " has no energy left to be repaired.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    setHit(getHit() + amount);
    std::cout << "ClapTrap " << getName() << " is being repaired, its hit points/health is now " << getHit() << ".\n";
}