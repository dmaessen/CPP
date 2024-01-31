/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:22:06 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 14:34:57 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>

int main( void ) {
    int arr1[5] = {1, 2, 3, 4, 5};
    char arr2[2] = {'a', 'b'};
    
    size_t len1 = 5;
    size_t len2 = 2;
    
    // std::cout << "arr1 = " << &arr1 << ", &arr2 = " << &arr2 << '\n';
    // std::cout << "len1 = " << len1 << ", len2 = " << len2 << '\n';

    std::cout << "----------------\n";
    ::iter(arr1, len1, print<int>);
    std::cout << "----------------\n";
    ::iter(arr2, len2, print<char>);
    
    return 0;
}

