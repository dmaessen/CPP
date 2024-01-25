/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 14:36:53 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/Converter.hpp"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <limits.h>

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
        
void ScalarConverter::convert(std::string input) {
    Converter c; // is this the way??

    if (input == "+inff" || input == "-inff" || input == "nanf")
        c.conv_float(input);
    else if (input == "+inf" || input == "-inf" || input == "nan")
        c.conv_double(input);
    else {
        if (input.size() == 1 && ((input >= "A" && input <= "Z") || (input >= "a" && input <= "z"))) // char
            c.conv_char(input);
        else {
            size_t found = input.find(".");
            size_t ffound = input.find("f");
            int i = std::stoi(input);
            if (found != std::string::npos && ffound != std::string::npos && input.size() > 3)
                c.conv_float(input); // check for FLOAT_MIN // MAX ??
            else if (found != std::string::npos && input.size() > 2)
                c.conv_double(input); // check for MAX DOUBLE // MIN ??
            else if (i > INT_MIN && i <= INT_MAX)
                c.conv_int(input);
            else
                std::cout << "Error: type not recognized. Try again.\n";
        }
    }
}
