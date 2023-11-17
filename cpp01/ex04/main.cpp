/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:25:43 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/17 15:56:46 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Error: three parameters needed\n";
        return 1;
    }

    Replace r;
    std::ifstream infile;
    infile.open(argv[1], std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Error: opening infile\n";
        return 1;
    }
    std::ofstream outfile;
    std::string str;
    str = ".replace";
    outfile.open(argv[1] + str, std::ios::out);
    if (!outfile.is_open()) {
        std::cout << "Error: opening outfile\n";
        return 1;
    }
    
    r.setS1(argv[2]);
    r.setS2(argv[3]);
    if (r.getS1() == "" || r.getS2() == "") {
        std::cout << "Error: strings cannot be empty\n";
        return 1;
    }
    
    std::string line;
    std::string temp;
    std::size_t len = r.getS1().size();
    while (std::getline(infile, line)){
        while (1) {
            size_t pos = line.find(r.getS1());
            if (pos < line.size())
            {
                temp = line.substr(0, pos);
                outfile << temp << r.getS2();
                temp = line.substr(pos + len, line.size());
                outfile << temp << '\n';
                break ;
            }
            else {
                outfile << line << '\n';
                break ;
            }
        }
    }
    infile.close();
    outfile.close();
    return 0;
}