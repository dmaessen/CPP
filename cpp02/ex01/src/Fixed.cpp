/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:29:23 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/28 14:50:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const float fl) {
	// what do f need to do here ??
	std::cout << "Float constructor called\n";
}

float Fixed::toFloat(void) const {

}

Fixed::Fixed(const int i) {
	// what do i need to do here
	m_value = i ; // << m_frac
	std::cout << "Int constructor called\n";
}

int Fixed::toInt(void) const {

}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
// implement the operation << thing
// inserts a floating-point representation of m_value into the outstream passed as paramter