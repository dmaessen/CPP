/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/21 13:03:51 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int                 m_value;
        static const int    m_frac;

    public:
        Fixed(void); // default constructor
        Fixed(const Fixed& copy); // copy constructor
        Fixed& operator=(const Fixed); // assignment
        ~Fixed(void); // destructor
        
        int                 getRawBits( void ) const; // returns the raw value of the fixed-point value
        void                setRawBits( int const raw ); // sets the raw value of the fixed-point nb
};

#endif
