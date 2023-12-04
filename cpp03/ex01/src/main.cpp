/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/04 15:43:13 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include <iostream>

int main( void )
{
    //ClapTrap c ("John");
    ClapTrap c2 ("Kyle");

    ScavTrap s ("Alice");
    
    // c.attack(c2.getName());
    // c2.attack(c.getName());
    // c.takeDamage(10);
    c2.takeDamage(6);
    c2.beRepaired(20);
    c2.takeDamage(6);
    
    s.attack(c2.getName());
    c2.attack(s.getName());
    s.takeDamage(40);
    c2.attack(s.getName());
    c2.takeDamage(10);
    s.guardGate();

    return 0;
}