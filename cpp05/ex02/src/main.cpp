/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:55 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/19 11:35:18 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
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

    std::cout << "----------------\n";
    Form f ("taxes", 10, 5);
    
    f.beSigned(b2); // not poss
    b2.signForm(f);
    f.beSigned(b);
    b.signForm(f);

    return 0;
}