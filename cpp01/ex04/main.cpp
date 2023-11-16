/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:25:43 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/16 15:57:31 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 4)
    {
        std::cout << "Error: three parameters needed\n";
        return 1;
    }

    std::ifstream infile;
    infile.open(argv[1], std::ios::in); // check if failed??
    if (!infile.is_open())
    {
        std::cout << "Error: opening infile\n";
        return 1;
    }
    std::ofstream outfile;
    std::string str;
    str = ".replace";
    outfile.open(argv[1] + str, std::ios::out);
    if (!outfile.is_open())
    {
        std::cout << "Error: opening outfile\n";
        return 1;
    }
    // here start to check
    infile.close();
    outfile.close();
    return 0;
}