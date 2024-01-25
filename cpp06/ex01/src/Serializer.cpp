/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:36:01 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 16:15:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){
    std::cout << "Default constructor called\n";
}

Serializer::~Serializer(void){
    std::cout << "Destructor called on\n";
}

Serializer::Serializer(const Serializer &copy){
    *this = copy;
    std::cout << "Copy constructor called\n";
}

Serializer& Serializer::operator=(const Serializer &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignement operator called\n";
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    std::uintptr_t u = reinterpret_cast<std::uintptr_t>(&ptr);
    return u;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* d = reinterpret_cast<Data*>(raw); // not the address or something of it right?
    return d; // or its address??
}