/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:28:11 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/27 13:46:26 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: wrong amount of arguments\n";
        return 1;
    }
    
	BitcoinExchange b;
	b.loadDatabase();
	b.validateInput(argv[1]);

    return 0;
}
