/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:19 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 15:10:21 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/C.hpp"

C::C(void) {
    std::cout << "[C] Default constructor called\n";
}

C::~C(void){
    std::cout << "[C] Destructor called on\n";
}