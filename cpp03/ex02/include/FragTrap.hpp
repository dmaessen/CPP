#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:

    public:
        FragTrap(std::string name); // default constructor
        FragTrap(const FragTrap &copy); // copy constructor
    	FragTrap& operator=(const FragTrap &copy); // assignment
		~FragTrap(void);

        void attack(const std::string& target);

		void highFivesGuys(void);
};

#endif