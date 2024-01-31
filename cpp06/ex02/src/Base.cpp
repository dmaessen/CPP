/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:16 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 11:20:02 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base::~Base(void){
    //std::cout << "[Base] Destructor called on\n";
}

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base * generate(void){
    std::srand(std::time(nullptr));
    int nb = 1 + std::rand() / ((RAND_MAX + 1u) / 3);
    
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
    bool aType = false;
    bool bType = false;
    bool cType = false;

    try {
        A& a = dynamic_cast<A&>(p);
        aType = true;
        (void)a;
    }
    catch (const std::bad_cast&){
        // nothing
    }
    try {
        B& b = dynamic_cast<B&>(p);
        bType = true;
        (void)b;
    }
    catch (const std::bad_cast&){
        // nothing
    }
    try {
        C& c = dynamic_cast<C&>(p);
        cType = true;
        (void)c;
    }
    catch (const std::bad_cast&){
        // nothing
    }

    if (aType == true)
        std::cout << "p is type: A\n";
    else if (bType == true)
        std::cout << "p is type: B\n";
    else if (cType == true)
        std::cout << "p is type: C\n";
    else
        std::cout << "type unkown\n";
}