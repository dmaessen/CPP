#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl(void) = default;
		~Harl(void) = default;

		// setters-getters??
		void complain( std::string level ); // via pointer to member functions
};

#endif