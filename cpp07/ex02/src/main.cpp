/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:36 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/02 11:32:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include "../include/Array.tpp"
#include <iostream>

int main(void)
{
    // int * f = new int();
    // std::cout << *f << "\n"; // test
    
    Array<int> a(6);
	Array<int> b;
    b = a;

	std::cout << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';

	a[4] = 7;
	std::cout << "a = " << a << '\n';
    b[0] = 1;
    std::cout << "b = " << b << '\n';
	
	std::cout << "\n----------------\n";
	try {
		std::cout << b[10] << '\n';
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------\n";
	std::cout << "size of a = " << a.size() << '\n';
	std::cout << "size of b = " << b.size() << '\n';

    return 0;
}