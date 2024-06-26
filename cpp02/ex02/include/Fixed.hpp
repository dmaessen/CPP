/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:23:52 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/29 19:06:19 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int                 m_value;
        static const int    m_frac;

    public:
        Fixed(void); // default constructor
        Fixed(const Fixed &copy); // copy constructor
        Fixed& operator=(const Fixed &copy); // assignment
        Fixed(const int i); // int constructor
		Fixed(const float fl); // float constructor
		~Fixed(void);
        
        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );

		float				toFloat( void ) const;
		int					toInt( void ) const;

        /* The 6 comparison operators: >, <, >=, <=, == and != */
        bool operator==(const Fixed& b) const;
        bool operator!=(const Fixed& b) const;
        bool operator<=(const Fixed& b) const;
        bool operator>=(const Fixed& b) const;
        bool operator<(const Fixed& b) const;
        bool operator>(const Fixed& b) const;
        
        /* The 4 arithmetic operators: +, -, *, and / */
        Fixed operator-(const Fixed& b) const;
        Fixed operator+(const Fixed& b) const;
        Fixed operator*(const Fixed& b) const;
        Fixed operator/(const Fixed& b) const;

        /* pre-/post-increment pre-/post-decrement */
        Fixed& operator++(); // pre
        Fixed& operator--();
        Fixed operator++(int); // post
        Fixed operator--(int);

        /* overload min/max */
        static Fixed min(const Fixed& a, const Fixed& b);
        static Fixed max(const Fixed& a, const Fixed& b);
        static Fixed min(Fixed& a, Fixed& b); 
        static Fixed max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif