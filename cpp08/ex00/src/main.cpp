/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:46:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/06 12:57:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int main(void)
{
    std::vector<int> v = { 1, 40, 54, 71, 76, 17 };
    
    int res = easyfind(v, 71);
    std::cout << "int 71: ";
    if (res != -1)
        std::cout << "this int occurs in the container.\n";
    else
        std::cout << "this int doesn't occur in the container.\n";
    
    std::cout << "----------------\n";
    res = easyfind(v, 2);
    std::cout << "int 2: ";
    if (res != -1)
        std::cout << "this int occurs in the container.\n";
    else
        std::cout << "this int doesn't occur in the container.\n";
    return 0;
}
