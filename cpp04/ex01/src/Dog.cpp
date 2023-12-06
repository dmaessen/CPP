/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:45:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/06 15:28:44 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    type = "Dog";
    this->type = new Brain(); // test this and make sure we have getters and setters
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