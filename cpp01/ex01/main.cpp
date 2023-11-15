/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:03:28 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 13:44:25 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    Zombie *z;
    Zombie *z2;
    
    z = zombieHorde(10, "John");
    delete[] z;
    z2 = zombieHorde(2, "Johnny");
    delete[] z2;
    return 0;    
}
