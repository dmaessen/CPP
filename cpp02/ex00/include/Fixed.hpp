/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:50:37 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/27 14:38:43 by domi             ###   ########.fr       */
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
        Fixed(const Fixed &copy); // copy constructor
        Fixed& operator=(const Fixed &copy); // assignment
        ~Fixed(void);
        
        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );
};

#endif
