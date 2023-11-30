/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:29:23 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/30 14:47:28 by dmaessen         ###   ########.fr       */
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
    this->m_value = copy.m_value;
}

Fixed& Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called\n";
    setRawBits(copy.m_value);
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits( int const raw ) {
    m_value = raw;
}

int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called\n";
    return m_value;
}

Fixed::Fixed(const float fl) {
	// multiplying 1 by 2^m_frac(8)
	m_value = roundf(fl * (1 << m_frac));
    // std::cout << "in float fl ==" << fl << "value == " << m_value << '\n'; // to rm
	std::cout << "Float constructor called\n";
}

float Fixed::toFloat(void) const {
	float newfl = (float)m_value / (float)(1 << m_frac);
    return newfl;
}

Fixed::Fixed(const int i) {
	m_value = i << m_frac; // left shiffting i by 8 positions
	std::cout << "Int constructor called\n";
}

int Fixed::toInt(void) const {
    return (int)this->toFloat();
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}

bool Fixed::operator==(const Fixed &b) const {
    return (this->toFloat() == b.toFloat()); // question if we ref to m_value or something toFloat()
}

bool Fixed::operator!=(const Fixed &b) const {
    return (this->toFloat() != b.toFloat()); // question if we ref to m_value or something toFloat()
}

bool Fixed::operator<=(const Fixed &b) const {
    return (this->toFloat() <= b.toFloat());
}

bool Fixed::operator>=(const Fixed &b) const {
    return (this->toFloat() >= b.toFloat());
}

bool Fixed::operator<(const Fixed &b) const {
    return (this->toFloat() < b.toFloat());
}

bool Fixed::operator>(const Fixed &b) const {
    return (this->toFloat() > b.toFloat());
}

Fixed Fixed::operator-(const Fixed& b) const {
    return (this->toFloat() - b.toFloat());
}

Fixed Fixed::operator+(const Fixed& b) const {
    return (this->toFloat() + b.toFloat());
}

Fixed Fixed::operator*(const Fixed& b) const {
    return (this->toFloat() * b.toFloat());
}

Fixed Fixed::operator/(const Fixed& b) const {
    return (this->toFloat() / b.toFloat());
}

Fixed& Fixed::operator++() {
    ++m_value;
    return *this;
}

Fixed& Fixed::operator--() {
    --m_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++*this;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --*this;
    return temp;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
    // return (a < b) ? a : b; // if true returns a else b
}

Fixed Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
    // return (a < b ? b : a); 
}

Fixed Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b; // if true returns a else b
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
    return (a < b ? b : a); 
}