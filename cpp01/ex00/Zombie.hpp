/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:52:16 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/14 15:05:16 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie 
{
    private:
        std::string m_name;
    
    public:
        Zombie(void);
        ~Zombie(void);
        
        void announce(void);
        
        void		setName(std::string input);
        std::string	getName() const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif