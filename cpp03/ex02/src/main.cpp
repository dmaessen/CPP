/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 16:51:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include <iostream>

int main( void )
{
    ClapTrap c ("Kyle");
    ScavTrap s ("Alice");
    FragTrap f ("Felix");

    std::cout << "\n";
    s.guardGate();

    std::cout << "\n";
    f.highFivesGuys();
    f.highFivesGuys();
    f.attack(s.getName());
    s.takeDamage(f.getAttack());
    c.attack(f.getName());
    f.takeDamage(c.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    s.attack(f.getName());
    f.takeDamage(s.getAttack());
    f.highFivesGuys();
    std::cout << "\n";
    
    return 0;
}
