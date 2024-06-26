/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 16:48:17 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include <iostream>

int main( void )
{
    ClapTrap c ("Kyle");
    ScavTrap s ("Alice");

    std::cout << "\n";
    s.attack(c.getName());
    c.takeDamage(s.getAttack());
    c.attack(s.getName());
    s.takeDamage(c.getAttack());
    c.attack(s.getName());
    s.takeDamage(c.getAttack());
    s.guardGate();
    std::cout << "\n";

    return 0;
}