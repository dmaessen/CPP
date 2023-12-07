/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:45:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 14:56:30 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    type = "Dog";
    std::cout << "Default constructor called on " << getType() << "\n";
}

Dog::Dog(const Dog &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Destructor called on " << getType() << "\n";
}

void Dog::makeSound( void ) const {
    std::cout << "WOUUUUF... (yells the dog)\n";
}