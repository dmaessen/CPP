/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:55 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:45:47 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

int main(void) {
    Bureaucrat b("Alice", 2);
    Bureaucrat b2("John", 151);
    
    std::cout << '\n' << b << "[incrementing] " << '\n';
    b.incrGrade();
    std::cout << b << '\n';
    std::cout << b << "[incrementing] " << '\n';
    b.incrGrade();
    std::cout << b << '\n';
    std::cout << b << "[decrementing] " << '\n';
    b.decrGrade();
    std::cout << b << '\n';
    std::cout << b2 << "[incrementing] " << '\n';
    b2.incrGrade();
    std::cout << b2 << '\n';

    return 0;
}