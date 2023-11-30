/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:38 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/30 15:44:21 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
    private:
        std::string		m_name;
        unsigned int	m_hit;
        unsigned int	m_energy;
        unsigned int	m_attack;

    public:
        ClapTrap(std::string name); // default constructor
        ClapTrap(const ClapTrap &copy); // copy constructor
        ClapTrap& operator=(const ClapTrap &copy); // assignment
		~ClapTrap(void);

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