/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 11:40:01 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include <iostream>

Animal::Animal() {
    type = "Animal";
    std::cout << "Default constructor called on " << getType() << " in Animal\n";
}

Animal::Animal(const Animal &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Destructor called on " << getType() << " in Animal\n";
}

std::string Animal::getType(void) const {
    return type;
}

void Animal::setType(std::string input) {
    type = input;
}

void Animal::makeSound( void ) const {
    std::cout << "[animal makes a sound]...\n";
}


