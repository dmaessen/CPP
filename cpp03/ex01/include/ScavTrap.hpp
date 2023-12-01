#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>

class ScavTrap
{
    private:
        std::string		m_name;
        unsigned int	m_hit;
        unsigned int	m_energy;
        unsigned int	m_attack;

    public:
        ScavTrap(std::string name); // default constructor
        ScavTrap(const ScavTrap &copy); // copy constructor
        ScavTrap& operator=(const ScavTrap &copy); // assignment
		~ScavTrap(void);

		std::string getName( void ) const;
		unsigned int getHit( void ) const;
		unsigned int getEnergy( void ) const;
		unsigned int getAttack( void ) const;
		void setName( std::string name );
        void setHit( unsigned int const amount );
		void setEnergy( unsigned int const amount );
		void setAttack( unsigned int const amount );

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif