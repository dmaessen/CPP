/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 11:46:34 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <string>
#include <stdlib.h>

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

static void conv_char(std::string input) {
    std::cout << "char: '" << input << "'\n";
    char c = input[0];
    std::cout << "int: " << static_cast<int>(c) << '\n';
    std::cout << "float: " << static_cast<int>(c) << ".0f\n";
    std::cout << "double: " << static_cast<int>(c) << ".0\n";
}

static void conv_int(std::string input) {
    int i = std::stoi(input);
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    else
        std::cout << "char: non printable\n";
    if (i > INT_MIN && i <= INT_MAX)
    {
        std::cout << "int: " << input << "\n";
        std::cout << "float: " << input << ".0f\n";
    }
    else
    {
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
    }
    double d = static_cast<double>(i);
    if (d > -DBL_MAX && d <= DBL_MAX)
        std::cout << "double: " << d << ".0\n";
    else
        std::cout << "double: impossible\n";
}

static void conv_float(std::string input) {
    if (input == "-inff" || input == "+inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << input << '\n';
        if (input[0] == '-')
            std::cout << "double: -inf\n";
        else if (input[0] == '+')
            std::cout << "double: +inf\n";
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
        if (i > INT_MIN && i <= INT_MAX)
            std::cout << "int: " << static_cast<int>(f) << "\n";
        else
            std::cout << "int: impossible\n";
        if (input[input.size() - 2] == '0' && (f > FLT_MIN && f <= FLT_MAX))    
            std::cout << "float: " << f << ".0f\n";
        else if (input[input.size() - 2] != '0' && (f > FLT_MIN && f <= FLT_MAX))
            std::cout << "float: " << f << "f\n";
        else
            std::cout << "float: impossible\n";
        double d = static_cast<double>(f);
        if (input[input.size() - 2] == '0' && (d > -DBL_MAX && d <= DBL_MAX))    
            std::cout << "double: " << d << ".0\n";
        else if (input[input.size() - 2] != '0' && (d > -DBL_MAX && d <= DBL_MAX))
            std::cout << "double: " << d << "\n";
        else
            std::cout << "double: impossible\n";
    }
}

static void conv_double(std::string input) {
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
        if (i > INT_MIN && i <= INT_MAX)
            std::cout << "int: " << static_cast<int>(d) << "\n";
        else
            std::cout << "int: impossible\n";
        float f = static_cast<float>(d);
        if (input[input.size() - 2] == '0' && (f > FLT_MIN && f <= FLT_MAX))    
            std::cout << "float: " << f << ".0f\n";
        else if (input[input.size() - 2] != '0' && (f > FLT_MIN && f <= FLT_MAX))
            std::cout << "float: " << f << "f\n";
        else
            std::cout << "float: impossible\n";
        if (input[input.size() - 2] == '0' && (d > -DBL_MAX && d <= DBL_MAX))    
            std::cout << "double: " << d << ".0\n";
        else if (input[input.size() - 2] != '0' && (d > -DBL_MAX && d <= DBL_MAX))
            std::cout << "double: " << d << "\n";
        else
            std::cout << "double: impossible\n";
    }
}

void ScalarConverter::convert(std::string input) {
    if (input == "+inff" || input == "-inff" || input == "nanf")
        conv_float(input);
    else if (input == "+inf" || input == "-inf" || input == "nan")
        conv_double(input);
    else {
        if (input.size() == 1 && ((input >= "A" && input <= "Z") || (input >= "a" && input <= "z"))) // char
            conv_char(input);
        else {
            size_t found = input.find(".");
            size_t ffound = input.find("f");
            int i = std::stoi(input);
            if (found != std::string::npos && ffound != std::string::npos && input.size() > 3)
                conv_float(input);
            else if (found != std::string::npos && input.size() > 2)
                conv_double(input);
            else if (i > INT_MIN && i <= INT_MAX)
                conv_int(input);
            else
                std::cout << "Error: type not recognized. Try again.\n";
        }
    }
}