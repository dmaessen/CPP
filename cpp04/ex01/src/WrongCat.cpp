/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:33 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 15:04:36 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
    type = "WrongCat";
    std::cout << "Default constructor called on " << getType() << "\n";
}

WrongCat::WrongCat(const WrongCat &copy) {
    std::cout << "Copy constructor called on " << getType() << "\n";
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on " << this->getType() << "\n";
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << "Destructor called on " << getType() << "\n";
}

void WrongCat::makeSound( void ) const {
    std::cout << "ROOOAAR... (yells the broken-cat)\n";
}