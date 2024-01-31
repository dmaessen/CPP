/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:16 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 10:09:57 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base * generate(void){
    std::srand(std::time(nullptr));
    int nb = 1 + std::rand() / ((RAND_MAX + 1u) / 3);
    // std::cout << nb << '\n';
    
    Base *b;
    if (nb == 1)
        b = new A;
    else if (nb == 2)
        b = new B;
    else
        b = new C;
    return b;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C"
void identify(Base* p) {
    if (A* a_ptr = dynamic_cast<A*>(p))
        std::cout << "p is type: A\n";
    else if (B* b_ptr = dynamic_cast<B*>(p))
        std::cout << "p is type: B\n";
    else if (C* c_ptr = dynamic_cast<C*>(p))
        std::cout << "p is type: C\n";
    else
        std::cout << "type unkown\n";
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p) {
    // if ((dynamic_cast<A&>(p)) != (nullptr))
    //     std::cout << "p is type: A\n";
    // else if (B& b_ptr = dynamic_cast<B&>(p))
    //     std::cout << "p is type: B\n";
    // else if (C& c_ptr = dynamic_cast<C&>(p))
    //     std::cout << "p is type: C\n";
    // else
    //     std::cout << "type unkown\n";

    bool aType = false;
    bool bType = false;
    bool cType = false;

    try {
        dynamic_cast<A&>(p);
        aType = true;
    }
    catch (const std::bad_cast&){
    }
    try {
        dynamic_cast<B&>(p);
        bType = true;
    }
    catch (const std::bad_cast&){
    }
    try {
        dynamic_cast<C&>(p);
        cType = true;
    }
    catch (const std::bad_cast&){
    }

    if (aType == true) {
        A& aRef = dynamic_cast<A&>(p); // put this in a try catch without bool and print statement directly
        std::cout << "p is type: A\n";
    }
    else if (bType == true) {
        B& aRef = dynamic_cast<B&>(p);
        std::cout << "p is type: B\n";
    }
    else if (cType == true) {
        C& aRef = dynamic_cast<C&>(p);
        std::cout << "p is type: C\n";
    }
    else
        std::cout << "type unkown\n";
}