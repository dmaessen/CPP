#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHit(100);
	setEnergy(50);
	setAttack(20);
	std::cout << "ScavTrap default constructor called for " << getName() << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
    std::cout << "ScavTrap copy constructor called\n";
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy) {
    std::cout << "ScavTrap copy assignment operator called\n";
    setName(copy.getName());
    setHit(copy.getHit());
    setEnergy(copy.getEnergy());
    setAttack(copy.getAttack());
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called on " << getName() << "\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
    if (getEnergy() < 1)
    {
        std::cout << "ScavTrap " << getName() << " has no energy left to attack.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << "ScavTrap " << getName() << " attacks " << target \
    << ", causing " << getAttack() << " points of damage!\n";
}
