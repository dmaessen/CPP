/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 15:04:10 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    type = "WrongAnimal";
    std::cout << "Default constructor called on " << getType() << " in WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "Destructor called on " << getType() << " in WrongAnimal\n";
}

std::string WrongAnimal::getType(void) const {
    return type;
}

void WrongAnimal::setType(std::string input) {
    type = input;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "[no sound]...\n";
}
