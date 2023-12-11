/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:45:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 12:58:23 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    type = "Dog";
    std::cout << "Default constructor called on " << getType() << "\n";
    m_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal() {
    std::cout << "Copy constructor called on " << getType() << "\n";
    type = copy.type;
    delete (m_brain);
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
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return (*this);
}

Dog::~Dog(void) {
    delete(m_brain);
    std::cout << "Destructor called on " << getType() << "\n";
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