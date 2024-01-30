/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/30 14:38:55 by dmaessen         ###   ########.fr       */
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
    Base *b3 = generate();

    identify(b);
    identify(b1);
    identify(b2);
    
    identify(*b3);

    return 0;
}