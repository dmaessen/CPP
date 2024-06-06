/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:07 by dmaessen          #+#    #+#             */
/*   Updated: 2024/06/06 15:31:05 by domi             ###   ########.fr       */
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
    p.start(argc, argv);

    return 0;
}