/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:29:23 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/29 15:37:32 by dmaessen         ###   ########.fr       */
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
    // std::cout << "getRawBits member function called\n";
    return m_value;
}

Fixed::Fixed(const float fl) {
	// multiplying 1 by 2^m_frac(8)
	m_value = roundf(fl * (1 << m_frac));
    // std::cout << "in float fl ==" << fl << "value == " << m_value << '\n'; // to rm
	std::cout << "Float constructor called\n";
}

float Fixed::toFloat(void) const {
	float newfl = (float)m_value / (1 << m_frac);
    return newfl;
}

Fixed::Fixed(const int i) {
	m_value = i << m_frac; // left shiffting i by 8 positions
	std::cout << "Int constructor called\n";
}

int Fixed::toInt(void) const {
	//return m_value; dividing it again
    return this->toFloat();
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	//std::cout << "we're here  TO FLOAT ==" << f.toFloat() << '\n'; // to rm
    out << f.toFloat();
    return out;
}
// implement the operation << thing
// inserts a floating-point representation of m_value into the outstream passed as paramter