/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 10:20:32 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>

int main(void)
{
    Base *b = generate();
    Base *b1 = generate();
    Base *b2 = generate();

    std::cout << "---------\n";
    identify(b);
    identify(b1);
    identify(b2);
    
    std::cout << "---------\n";
    identify(*b);
    identify(*b1);
    identify(*b2);

    return 0;
}