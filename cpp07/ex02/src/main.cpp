/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:36 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/01 16:46:26 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include "../include/Array.tpp" // needed?
#include <iostream>

int main(void)
{
        

    int * f = new int();
    std::cout << *f << "\n"; // test
    


    Array<int> a(2);
	Array<int> b;
    b = a;

	std::cout << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';

    a[0] = 1;
    std::cout << "a = " << a << '\n';

	try {
		std::cout << a[5] << '\n';
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << a.size() << '\n';
    
    // don't forget to delete -- if needed

    return 0;
}