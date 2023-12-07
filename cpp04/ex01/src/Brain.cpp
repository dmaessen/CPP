/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:54 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 16:22:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain(void){
    ideas[100] = "draw, paint, sing...";
    std::cout << "Default constructor called on Brain" << "\n";
}

Brain::Brain(const Brain &copy) {
    std::cout << "Copy constructor called on Brain" << "\n";
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy) {
    setIdeas(copy.ideas[100]);
    std::cout << "Copy assignment operator called on Brain" << "\n";
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Destructor called on Brain" << "\n";
}

void Brain::setIdeas( std::string input ) {
    ideas[100] = input;
}

std::string Brain::getIdeas(void) const {
    return ideas[100];
}
