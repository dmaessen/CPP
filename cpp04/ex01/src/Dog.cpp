/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:45:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 15:05:02 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    type = "Dog";
    std::cout << "Default constructor called on " << getType() << "\n";
    this->_brain = new Brain(); // test this and make sure we have getters and setters
}

Dog::Dog(const Dog &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

Dog& Dog::operator=(const Dog &copy) {
    setType(copy.type);
    setBrain(copy._brain);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

Dog::~Dog(void) {
    delete(this->_brain);
    std::cout << "Destructor called on " << getType() << "\n";
}

Brain& Dog::getBrain( void ) const {
    return *_brain;
}

void Dog::setBrain( Brain* input ) {
    _brain = input;
}

void Dog::makeSound( void ) const {
    std::cout << "WOUUUUF... (yells the dog)\n";
}