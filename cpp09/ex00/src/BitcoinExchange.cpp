/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:44 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/28 10:18:33 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cmath>

BitcoinExchange::BitcoinExchange(void) {
    // std::cout << "Default constructor called\n";
}

BitcoinExchange::~BitcoinExchange(){
    // std::cout << "Destructor called\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    // std::cout << "Copy constructor called\n";
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
    //std::cout << "Copy assignment operator called\n";
     if (this != &src)
        *this = src;
    return (*this);
}

int BitcoinExchange::loadDatabase() {
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
		_m[date] = nb; // loss of precision here
    }
    infile.close();
    return 0;
}

int BitcoinExchange::validateInput(char *argv) {
    std::ifstream infile;
	infile.open(argv, std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Error: opening input file\n";
        return 1;
    }
    
	std::string date1;
	std::string value;
	float nb;
    std::string line;
	std::getline(infile, line);
    while (std::getline(infile, line)){
        date1 = line.substr(0, 10);
        if (isDate(date1) == false)
        {
            std::cout << "Error: date is incorrect\n";
            continue ;
        }
		value = line.substr(13, line.size());
		nb = std::stof(value);
		if (nb < 0 || nb > 1000)
			std::cout << "Error: incorrect value, needs to be between 0 and 1000\n";
		else {
            if (_m.find(date1) != _m.end())
                std::cout << date1 << " => " << nb << " = " << _m[date1] * nb << '\n';
            else if (_m.empty())
                    std::cout << "Error: map is empty\n";
            else {
                std::map<std::string, float>::iterator itlow;
                itlow = _m.lower_bound(date1);
                    std::cout << itlow->first << " => " << nb << " = " << itlow->second * nb << '\n';
            }
		}
    }
    return 0;
}

bool BitcoinExchange::isDate(std::string date) {
    const char* ccdate = date.c_str();
    struct tm tm;
    if (!strptime(ccdate, "%Y-%m-%d", &tm))
        return false;
    return true;
}
