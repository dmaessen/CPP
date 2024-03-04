/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:07 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/04 15:00:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2) // or 3 don't know yet
    {
        std::cout << "Error\n";
        return 1;
    }

    

    // 1: validate if all positive and int (not max+); else error
    // 2: init list ++ vector
    // 3: split elements in pairs of 2
    // 4: recursively sort largest (swap if needed??)
    // 5: create main chain (with a 2temps)


    // make a print ft with all four lines


    return 0;
}