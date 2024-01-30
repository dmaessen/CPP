/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:57:18 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/30 13:51:05 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(void){
    ScalarConverter s;// make constructer private to make not instantiatable (look into Singelton)
    
    std::string input = "a";
    s.convert(input);
    std::cout << "---------\n";
    input = "A";
    s.convert(input);
    std::cout << "---------\n";
    input = "33";
    s.convert(input);
    std::cout << "---------\n";
    input = "2147483647";
    s.convert(input);
    std::cout << "---------\n";
    input = "-2";
    s.convert(input);
    std::cout << "---------\n";
    input = "-2.1f";
    s.convert(input);
    std::cout << "---------\n";
    input = "-inff";
    s.convert(input);
    std::cout << "---------\n";
    input = "4.2";
    s.convert(input);
    std::cout << "---------\n";
    input = "nan";
    s.convert(input);
    std::cout << "---------\n";
    input = "-inf";
    s.convert(input);

    return 0;
}

