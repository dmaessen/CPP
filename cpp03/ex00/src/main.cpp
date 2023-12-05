/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:56:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 16:46:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

int main( void )
{
    ClapTrap c ("John");
    ClapTrap c2 ("Kyle");
    
    std::cout << "\n";
    c.attack(c2.getName());
    c2.takeDamage(c.getAttack());
    c2.attack(c.getName());
    c.takeDamage(c2.getAttack());
    c.beRepaired(20);
    c.takeDamage(c2.getAttack());
    c2.takeDamage(c.getAttack());
    std::cout << "\n";

    return 0;
}
