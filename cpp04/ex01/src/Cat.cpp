/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    type = "Cat";
    this->type = new Brain(); // test this and make sure we have getters and setters
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