/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 15:43:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal() {
    type = "Animal";
    std::cout << "Default constructor called on " << getType() << "\n";
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
    std::cout << "Destructor called on " << getType() << "\n";
}

std::string Animal::getType(void) const {
    return type;
}

void Animal::setType(std::string input) {
    type = input;
}

void Animal::makeSound() {
    if (getType() == "Dog")
        std::cout << "WOUUUUF... (yells the dog)\n";
    else if (getType() == "Cat")
        std::cout << "MIAAAAOUUUUU... (yells the cat)\n";
    else
        std::cout << "[no sound]... (this animal doesn't have a type yet)\n";
    
}