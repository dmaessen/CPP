/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:53:34 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 14:10:58 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Init.hpp"
#include "../include/Serializer.hpp"
#include <iostream>

Init::Init(void){
    std::cout << "Default constructor called\n";
}

Init::~Init(void){
    std::cout << "Destructor called on\n";
}

Init::Init(const Init &copy){
    *this = copy;
    std::cout << "Copy constructor called\n";
}

Init& Init::operator=(const Init &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignement operator called\n";
    return *this;
}

// void Init::convert(Data* d) {
//     Serializer s; // is this the way?
    
//     std::uintptr_t u = s.serialize(d);
//     std::cout << "[after serialize] Value of u: " << u << '\n';
    
//     Data* new_d = s.deserialize(u);
//     std::cout << "[after deserialize] Value of new_Data: "  << new_d << '\n'; // or the address or something of it??
//     std::cout << "[after deserialize] Value of new_Data->c: " << new_d->c << '\n';
// }