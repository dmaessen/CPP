/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:41 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/12 16:11:51 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    
    std::cout << "-------------------\n";
    try {
        std::cout << "shortest span: " << sp.shortestSpan() << '\n';
    }
    catch(const std::exception& e) {
		std::cerr << e.what();
	}
    
    std::cout << "-------------------\n";
    
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortest span: " << sp.shortestSpan() << '\n';
    std::cout << "longest span: " << sp.longestSpan() << '\n';

    std::cout << "-------------------\n";
    // test with at least 10 000nb with addManyNumbers()
    Span sp2 = Span(10001);
    sp2.addManyNumbers();
    std::cout << "shortest span: " << sp2.shortestSpan() << '\n';
    // std::cout << "longest span: " << sp2.longestSpan() << '\n';
    
    return 0;
}