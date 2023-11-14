/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:20 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:49 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie z1;
    Zombie z2;
    Zombie *z3;
    
    z1.setName("John");
    z1.announce();
    z2.setName("Johnny");
    z2.announce();

    z3 = newZombie("Johanna");
    z3->announce();
    delete(z3);
    
    randomChump("Joe");
}
