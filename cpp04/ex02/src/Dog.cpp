/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:45:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/12 14:47:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    type = "Dog";
    std::cout << "Default constructor called on Dog\n";
    m_brain = new Brain();
}

Dog::Dog(const Dog &copy) {
    std::cout << "Copy constructor called on Dog\n";
    type = copy.type;
    m_brain = new Brain(*copy.m_brain);
    return ;
}

Dog& Dog::operator=(const Dog &copy) {
    if (this != &copy)
    {
        type = copy.type;
        delete (m_brain);
        m_brain = new Brain(*copy.m_brain);
    }
    std::cout << "Copy assignment operator called on Dog\n";
    return (*this);
}

Dog::~Dog(void) {
    delete(m_brain);
    std::cout << "Destructor called on Dog\n";
}

Brain& Dog::getBrain( void ) const {
    return *m_brain;
}

void Dog::setBrain( Brain* input ) {
    m_brain = input;
}

void Dog::makeSound( void ) const {
    std::cout << "WOUUUUF... (yells the dog)\n";
}

std::string Dog::getType(void) const {
    return type;
}

void Dog::setType(std::string input) {
    type = input;
}