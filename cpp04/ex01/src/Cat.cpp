/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 12:58:13 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    type = "Cat";
    std::cout << "Default constructor called on " << getType() << "\n";
    m_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal() {
    std::cout << "Copy constructor called on " << getType() << "\n";
    type = copy.type;
    delete(m_brain);
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
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return (*this);
}

Cat::~Cat(void) {
    delete(m_brain);
    std::cout << "Destructor called on " << getType() << "\n";
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