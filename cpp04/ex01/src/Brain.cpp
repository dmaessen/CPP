/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:54 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/06 15:10:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain(void){
    // we do something with ideas??
    std::cout << "Default constructor called on Brain" << "\n";
}

Brain::Brain(const Brain &copy) {
    std::cout << "Copy constructor called on Brain" << "\n";
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy) {
    //setType(copy.type); // ideas??
    std::cout << "Copy assignment operator called on Brain" << "\n";
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Destructor called on Brain" << "\n";
}