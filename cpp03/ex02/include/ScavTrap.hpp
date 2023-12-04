#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:

    public:
        ScavTrap(std::string name); // default constructor
        ScavTrap(const ScavTrap &copy); // copy constructor
        ScavTrap& operator=(const ScavTrap &copy); // assignment
		~ScavTrap(void);

        void attack(const std::string& target);

		void guardGate();
};

#endif