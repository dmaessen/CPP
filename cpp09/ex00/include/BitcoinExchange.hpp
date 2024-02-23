/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:28:16 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/23 13:19:41 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _m;

    public:
        BitcoinExchange(void);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src); // copy constructor
        BitcoinExchange& operator=(const BitcoinExchange &csrc); // assignment
    
};

#endif