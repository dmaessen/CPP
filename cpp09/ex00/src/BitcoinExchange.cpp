/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:47:44 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/23 10:54:22 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    // std::cout << "Default constructor called\n";
}

BitcoinExchange::~BitcoinExchange(){
    // std::cout << "Destructor called\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    // std::cout << "Copy constructor called\n";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &csrc) {
    // std::cout << "Copy assignement called\n";
    return *this;
}
