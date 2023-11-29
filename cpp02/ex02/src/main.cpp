/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:04:34 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:24 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << (c == d) << std::endl; // returns 1 (if true)
    std::cout << (c != d) << std::endl;
    std::cout << (c <= d) << std::endl;
    std::cout << (c >= d) << std::endl;
    std::cout << (c < d) << std::endl;
    std::cout << (c > d) << std::endl;

    //std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}