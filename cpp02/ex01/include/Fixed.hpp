/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:23:52 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/28 14:32:41 by dmaessen         ###   ########.fr       */
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

        friend std::ostream& operator<<(std::ostream &out, const Fixed &f);
};

#endif