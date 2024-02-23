/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:28:11 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/23 13:22:49 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong amount of arguments.\n";
        return 1;
    }
    
	// first importe database then do this kind of loop for the input file only not database
	std::map<std::string, float> m; // or is the next one an double

	std::ifstream infile;
    infile.open("data.csv", std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Error: opening infile\n";
        return 1;
    }
    
    std::string date;
	std::string value;
	float nb;
    std::string line;
	std::getline(infile, line);
    while (std::getline(infile, line)){
        date = line.substr(0, 10);
		value = line.substr(11, line.size());
		nb = std::stof(value);
		if (nb < 0 || nb > 1000){
			std::cout << "Incorrect value, needs to be between 0 and 1000\n";
			break ;
		}
		else {
			m[date] = nb;
		}
    }
    infile.close();

	//TESTING
	// std::map<std::string, float>::iterator it = m.begin();
	// while (it != m.end())
	// {
	// 	std::cout << it->first << " " << it->second << '\n';
	// 	++it;
	// }

    return 0;
}