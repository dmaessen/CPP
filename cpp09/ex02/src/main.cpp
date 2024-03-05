/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:07 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/05 11:14:01 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2) {
        std::cout << "Error: worng amount of arguments\n";
        return 1;
    }

    PmergeMe p;
    if (p.validateInput(argv)) {
        std::cout << "Error: invalid input\n";
        return 1;
    }
    p.loadInput(argv);

    // 1: validate if all positive and int (not max+); else error
        // then print the before line
    // 2: init list ++ vector
    // 3: split elements in pairs of 2
    // 4: recursively sort largest (swap if needed??)
    // 5: create main chain (with a 2temps)


    // make a print ft with all four lines


    return 0;
}