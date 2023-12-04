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
	std::cout << "FragTrap " << getName() << "'s high fives request was positive.\n";
}

void FragTrap::attack(const std::string& target) {
    if (getEnergy() < 1)
    {
        std::cout << "FragTrap " << getName() << " has no energy left to attack.\n";
        return ;
    }
    setEnergy(getEnergy() - 1);
    std::cout << "FragTrap " << getName() << " attacks " << target \
    << ", causing " << getAttack() << " points of damage!\n";
}
