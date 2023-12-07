/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 16:14:23 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    type = "Cat";
    std::cout << "Default constructor called on " << getType() << "\n";
    this->_brain = new Brain(); // test this and make sure we have getters and setters
}

Cat::Cat(const Cat &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy) {
    setType(copy.type);
    setBrain(copy._brain);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

Cat::~Cat(void) {
    delete(this->_brain);
    std::cout << "Destructor called on " << getType() << "\n";
}

Brain& Cat::getBrain( void ) const {
    return *_brain;
}

void Cat::setBrain( Brain* input ) {
    _brain = input;
}

void Cat::makeSound( void ) const {
    std::cout << "MIAAAAOUUUUU... (yells the cat)\n";
}