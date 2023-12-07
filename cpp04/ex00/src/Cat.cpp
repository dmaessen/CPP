/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 14:53:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    type = "Cat";
    std::cout << "Default constructor called on " << getType() << "\n";
}

Cat::Cat(const Cat &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

Cat& Cat::operator=(const Cat &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Destructor called on " << getType() << "\n";
}

void Cat::makeSound( void ) const {
    std::cout << "MIAAAAOUUUUU... (yells the cat)\n";
}
