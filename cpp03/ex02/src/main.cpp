/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/04 16:03:55 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include <iostream>

int main( void )
{
    //ClapTrap c ("John");
    ClapTrap c ("Kyle");
    ScavTrap s ("Alice");
    FragTrap f ("Felix");

    s.guardGate();
    c.takeDamage(6);
    c.beRepaired(20);
    c.takeDamage(6);
    s.attack(c.getName());
    c.attack(s.getName());
    s.takeDamage(40);
    c.attack(s.getName());
    c.takeDamage(10);
    f.highFivesGuys();
    f.highFivesGuys();
    f.attack(s.getName());
    f.takeDamage(50);
    f.takeDamage(15);
    f.highFivesGuys();
    
    return 0;
}