/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:29:18 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:00 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming \
for years whereas you started working here since last month.\n";
}

void Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ) {
    t_funct funct[4];
    
    funct[0].str = "debug";
    funct[0].f = &Harl::debug;
    funct[1].str = "info";
    funct[1].f = &Harl::info;
    funct[2].str = "warning";
    funct[2].f = &Harl::warning;
    funct[3].str = "error";
    funct[3].f = &Harl::error;
    
    Harl h;
    for (int i = 0; i < 4; i++) {
        if (funct[i].str == level)
        {
            (h.*(funct[i].f))();
            break ;
        }
    }
}