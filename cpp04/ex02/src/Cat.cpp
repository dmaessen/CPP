/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/12 15:55:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    type = "Cat";
    std::cout << "Default constructor called on Cat\n";
    m_brain = new Brain();
}

Cat::Cat(const Cat &copy) {
    std::cout << "Copy constructor called on Cat\n";
    type = copy.type;
    m_brain = new Brain(*copy.m_brain);
    return ;
}

Cat& Cat::operator=(const Cat &copy) {
    if (this != &copy)
    {
        type = copy.type;
        delete (m_brain);
        m_brain = new Brain(*copy.m_brain);
    }
    std::cout << "Copy assignment operator called on Cat\n";
    return (*this);
}

Cat::~Cat(void) {
    delete(m_brain);
    std::cout << "Destructor called on Cat\n";
}

Brain& Cat::getBrain( void ) const {
    return *m_brain;
}

void Cat::setBrain( Brain* input ) {
    m_brain = input;
}

void Cat::makeSound( void ) const {
    std::cout << "MIAAAAOUUUUU... (yells the cat)\n";
}

std::string Cat::getType(void) const {
    return type;
}

void Cat::setType(std::string input) {
    type = input;
}
