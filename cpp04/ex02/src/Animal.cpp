/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/12 15:11:19 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include <iostream>

Animal::Animal() {
    type = "Animal";
    std::cout << "Default constructor called on Animal\n";
}

Animal::Animal(const Animal &copy) {
    std::cout << "Copy constructor called on Animal\n";
    *this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
    setType(copy.type);
    std::cout << "Copy assignment operator called on Animal\n";
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Destructor called on Animal\n";
}
