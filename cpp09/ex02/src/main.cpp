/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:07 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/13 16:01:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2) {
        std::cout << "Error: wrong amount of arguments\n";
        return 1;
    }

    PmergeMe p;
    // std::string input = "";
    // for (int i = 0; i < argc; ++i)
    //     input.append(argv[i]).append(" ");
    p.sort(argc, argv);
    //p.loadInput(argv);

    // 1: validate if all positive and int (not max+); else error
        // then print the before line
    // 2: init list ++ vector
    // 3: split elements in pairs of 2
    // 4: recursively sort largest (swap if needed??)
    // 5: create main chain (with a 2temps)


    // make a print ft with all four lines



    // TO DO:
    // segfault on  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
    // find maybe ifs due to K

    


    return 0;
}