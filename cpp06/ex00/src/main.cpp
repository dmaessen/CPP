/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:57:18 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 12:30:41 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(void){
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

