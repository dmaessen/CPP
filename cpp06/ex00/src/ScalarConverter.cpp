/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 12:01:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter( void ){
    std::cout << "Default constructor called\n";
}

ScalarConverter::~ScalarConverter(void) {
    std::cout << "Destructor called on\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called\n";
    return (*this);
}