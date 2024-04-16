/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:44 by dmaessen          #+#    #+#             */
/*   Updated: 2024/04/15 14:59:09 by dmaessen         ###   ########.fr       */
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
#include <iomanip>

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
	double nb;
    std::string line;
	std::getline(infile, line);
    while (std::getline(infile, line)){
        date = line.substr(0, 10);
		value = line.substr(11, line.size());
		nb = std::stod(value);
		_m[date] = nb;
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
    
	std::string date;
	std::string value;
	double nb;
    std::string line;
	std::getline(infile, line);
    while (std::getline(infile, line)){
        date = line.substr(0, 10);
        if (isDate(date) == false || line[10] != ' ')
        {
            std::cout << "Error: date is incorrect\n";
            continue ;
        }
        if (line.size() < 14) {
            std::cout << "Error: wrong format, should be: 'date | value'\n";
            continue ;
        }
		value = line.substr(13, line.size());
        if ((line.size() - 13) > 10) {
            std::cout << "Error: incorrect value, needs to be between 0 and 1000\n";
            continue ;
        }
		else 
            nb = std::stod(value);
		if (nb < 0 || nb > 1000)
			std::cout << "Error: incorrect value, needs to be between 0 and 1000\n";
		else {
            if (_m.find(date) != _m.end())
                std::cout << date << " => " << nb << " = " << _m[date] * nb << '\n';
            else if (_m.empty())
                    std::cout << "Error: map is empty\n";
            else {
                std::map<std::string, double>::iterator itlow;
                itlow = _m.lower_bound(date);
                if (itlow != _m.begin())
                    itlow--;
                std::cout << date << " => " << nb << " = " << itlow->second * nb << '\n';
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
    
    std::string tmp;
    
    for (int i = 0; i < 4; i++) {
        tmp[i] = date[i];
    }
    int res = std::stoi(tmp);
    if (res < 0 || res > 4000)
        return false;
    
    int j = 0;
    std::string tmp2;
    for (int i = 5; i < 8; i++) {
        tmp2[j] = date[i];
        j++;
    }
    res = std::stoi(tmp2);
    if (res < 1 || res > 12)
        return false;
    
    j = 0;
    std::string tmp3;
    for (int i = 8; i < 10; i++) {
        tmp3[j] = date[i];
        j++;
    }
    res = std::stoi(tmp3);
    if (res < 1 || res > 31)
        return false;
    
    return true;
}
