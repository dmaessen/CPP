/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:04:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 13:42:52 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *newz = new Zombie[N]; // on the heap
    for (int i = 0; i < N; i++){
        newz[i].setName(name);
        newz[i].announce();
    }
    return newz;
}