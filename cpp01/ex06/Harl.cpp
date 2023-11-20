/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:49:24 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/20 15:07:39 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void ) {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming \
for years whereas you started working here since last month.\n";
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ) {
    t_funct funct[4];
    
    funct[0].str = "DEBUG";
    funct[0].f = &Harl::debug;
    funct[1].str = "INFO";
    funct[1].f = &Harl::info;
    funct[2].str = "WARNING";
    funct[2].f = &Harl::warning;
    funct[3].str = "ERROR";
    funct[3].f = &Harl::error;
    
    Harl h;
    int j = -1;
    for (int i = 0; i < 4; i++) {
        if (funct[i].str == level) {
            j = i;
            break ;
        }
    }

    switch (j)
    {
        case -1:
        {
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
        }
        case 0:
            (h.*(funct[0].f))();
        case 1:
            (h.*(funct[1].f))();
        case 2:
            (h.*(funct[2].f))();
        case 3:
            (h.*(funct[3].f))();  
        break ;
    }
}