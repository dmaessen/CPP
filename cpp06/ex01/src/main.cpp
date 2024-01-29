/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:12 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 14:13:58 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Init.hpp"
#include <iostream>

int main(void) {
    Data *d = new Data;
    d->i = 58;
    d->c = 'a';
    
    std::cout << "Original value of Data: " << d << '\n';
    std::cout << "Original value of Data->c: " << d->c << " Data->i: " << d->i << '\n';
    
    std::uintptr_t u = Serializer::serialize(d);
    std::cout << "[serialize]" << '\n';
    //std::cout << "[after serialize] Value of u: " << u << '\n';
    
    Data* new_d = Serializer::deserialize(u);
    std::cout << "[after deserialize] Value of new_Data: " << new_d << '\n';
    std::cout << "[after deserialize] new_Data->c: " << new_d->c << " new_Data->i: " << new_d->i << '\n';

    delete(d);

    return 0;
}
