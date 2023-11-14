/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:06:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    Zombie *newz = new(Zombie); // this mallocs space for zombie class -- on the heap
    newz->setName(name);
    return newz;
}
