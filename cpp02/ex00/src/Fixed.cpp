/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:34 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/27 14:37:47 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

const int Fixed::m_frac = 8;

Fixed::Fixed(void) {
    m_value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called\n";
    this->m_value = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called\n";
    setRawBits(copy.getRawBits());
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits( int const raw ) {
    m_value = raw;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return m_value;
}
