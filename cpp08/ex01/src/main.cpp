/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:41 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/12 22:21:06 by domi             ###   ########.fr       */
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
    // Span sp2 = Span(10001);

    try
	{
		Span sp2(10001);
		std::vector<int> vec2;
		std::srand(std::time(0));
		for(int i = 0; i < 100001; i++)	{
			int randNb = std::rand();
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



    
    try
    {
		std::vector<int>    vec3;
        Span    sp3(100000);
        for (int i = 0; i < 10000; i++)
            vec3.push_back(rand() % 9999);
        sp3.addNumbers(vec3.begin(), vec3.end());

        std::cout << "Shortest span: " << sp3.shortestSpan() << '\n';
        std::cout << "Longest span: " << sp3.longestSpan() << '\n';
	}
	catch (const std::exception &ex)
	{
		std::cerr << ex.what();
	}

    
    // sp2.addManyNumbers();
    //std::cout << "shortest span: " << sp2.shortestSpan() << '\n';
    // std::cout << "longest span: " << sp2.longestSpan() << '\n';
    
    return 0;
}