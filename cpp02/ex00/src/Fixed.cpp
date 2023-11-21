/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:34 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/21 13:07:50 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const &Fixed copy) {
    // do something witht copy thing
    std::cout << "Copy constructor called\n";
}


Fixed::~Fixed(void) {
    std::cout << "Destructor called\n";
}