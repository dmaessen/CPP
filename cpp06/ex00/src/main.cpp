/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:57:18 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 10:16:09 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

// JUST TEST ON LIMITS ON DOUBLE_FLOAT MAX MIN AND SO ON

int main(void){
    // make constructer private to make not instantiatable (look into Singelton)
    
    std::string input = "a";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "A";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "33";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "2147483647";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "-2";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "-2.1f";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "-inff";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "4.2";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "nan";
    ScalarConverter::convert(input);
    std::cout << "---------\n";
    input = "-inf";
    ScalarConverter::convert(input);

    return 0;
}

