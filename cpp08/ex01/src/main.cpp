/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:41 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 11:29:46 by dmaessen         ###   ########.fr       */
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
    try
	{
		Span sp2 = Span(10001);
		std::vector<int> vec2;
		std::srand(time(0));
		for(int i = 0; i < 100001; i++)	{
			int randNb = std::rand() % 10000;
			vec2.push_back(randNb);
		}
		sp2.addNumbers(vec2.begin(), vec2.end());
        
		std::cout << "Shortest Span: " << sp2.shortestSpan() << '\n';
        std::cout << "Longest Span: " << sp2.longestSpan() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what();
	}

    std::cout << "-------------------\n";
    try
    {
        Span sp3 = Span(100000);
		std::vector<int>    vec3;
        std::srand(time(0));
        for(int i = 0; i < 100000; i++)	{
			int randNb = std::rand() % 1000000;
			vec3.push_back(randNb);
		}
        sp3.addNumbers(vec3.begin(), vec3.end());
        vectIter smallIter = std::min_element(vec3.begin(), vec3.end());
        vectIter bigIter = std::max_element(vec3.begin(), vec3.end());
        std::cout << "Biggest element: " << *bigIter << " || Smallest element: " << *smallIter << '\n';
        std::cout << "Shortest span: " << sp3.shortestSpan() << '\n';
        std::cout << "Longest span: " << sp3.longestSpan() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what();
	}
    
    return 0;
}