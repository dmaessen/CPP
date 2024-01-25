/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 14:41:46 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/Converter.hpp"
#include <iostream>
#include <limits.h>

// Converter::Converter( void ){
//     //std::cout << "Default constructor called\n";
// }

// Converter::~Converter(void) {
//     //std::cout << "Destructor called on\n";
// }

// Converter::Converter(const Converter &copy) {
//     //std::cout << "Copy constructor called\n";
//     *this = copy;
// }

// Converter& Converter::operator=(const Converter &copy) {
//     if (this != &copy)
//         *this = copy;
//     //std::cout << "Copy assignment operator called\n";
//     return (*this);
// }

// WORKS
void Converter::conv_char(std::string input) {
    std::cout << "char: " << input << '\n';
    char c = input[0];
    std::cout << "int: " << static_cast<int>(c) << '\n';
    std::cout << "float: " << static_cast<int>(c) << ".0f\n"; // do we want this??
    std::cout << "double: " << static_cast<int>(c) << ".0\n"; // do we want this??
}

// SEEMS TO WORK -- maybe just check on the limits
void Converter::conv_int(std::string input) {
    int i = std::stoi(input);
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    else
        std::cout << "char: non printable\n";
    if (i > INT_MIN && i <= INT_MAX)
        std::cout << "int: " << input << "\n";
    else
        std::cout << "int: impossible\n";
    std::cout << "float: " << input << ".0f\n";
    double d = static_cast<double>(i); 
    std::cout << "double: " << d << ".0\n";
}

// WORKS -- just implement exceptions
void Converter::conv_float(std::string input) {
    if (input == "-inff" || input == "+inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << input << '\n';
        if (input[0] == '-')
            std::cout << "double: -inf\n"; // is this correct??
        else if (input[0] == '+')
            std::cout << "double: +inf\n"; // is this correct ??
        else
            std::cout << "double: nan\n";
        return ;
    }
    else {
        float f = std::stof(input);
        if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        else
            std::cout << "char: non printable\n";
        int i = static_cast<int>(f);
        if (i > INT_MIN && i <= INT_MAX) // check
            std::cout << "int: " << static_cast<int>(f) << "\n";
        else
            std::cout << "int: impossible\n";
        if (input[input.size() - 2] == '0') {
            std::cout << "float: " << f << ".0f\n";
            std::cout << "double: " << static_cast<double>(f) << ".0\n";
        }
        else {
            std::cout << "float: " << f << "f\n";
            std::cout << "double: " << static_cast<double>(f) << '\n';
        }  
    }
}

// WORKS
void Converter::conv_double(std::string input) {
    if (input == "-inf" || input == "+inf" || input == "nan") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        if (input[0] == '-')
            std::cout << "float: -inff\n";
        else if (input[0] == '+')
            std::cout << "float: +inff\n";
        else
            std::cout << "float: nanf\n";
        std::cout << "double: " << input << "\n";
        return ;
    }
    else {
        double d = std::stod(input);
        if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: non printable\n";
        int i = static_cast<int>(d);
        if (i > INT_MIN && i <= INT_MAX) // check
            std::cout << "int: " << static_cast<int>(d) << "\n";
        else
            std::cout << "int: impossible\n";
        if (input[input.size() - 1] == '0') {
            std::cout << "float: " << static_cast<float>(d) << ".0f\n";
            std::cout << "double: " << d << ".0\n";
        }
        else {
            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << d << '\n';
        }

    }
}