/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:12 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 16:14:35 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data *d = new Data; // to delete??
    d->i = 50;
    d->c = 'a';
    
    std::cout << "Original value of Data: " << &d << '\n';
    
    std::uintptr_t u = Serializer::serialize(d);
    std::cout << "[after serialize] Value of u: " << std::showbase << std::hex << u << '\n';
    
    Data new_d = Serializer::deserialize(u);
    std::cout << "[after deserialize] Value of new_Data: " << std::showbase << std::hex << u << '\n';

    delete(d);
    
    return 0;
}