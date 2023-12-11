/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:54 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 11:37:20 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain(void){
    std::cout << "Default constructor called on Brain" << "\n";
    for (int i = 0; i < 100; ++i)
        m_ideas[i] = "";
}

Brain::Brain(const Brain &copy) {
    std::cout << "Copy constructor called on Brain" << "\n";
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy) {
    std::cout << "Copy assignment operator called on Brain" << "\n";
    if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->m_ideas[i] = copy.m_ideas[i];
		}
	}
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Destructor called on Brain" << "\n";
}

void Brain::setIdeas( std::string input, int i ) {
    this->m_ideas[i] = input;
}

std::string Brain::getIdeas(int i) const {
    return (this->m_ideas[i]);
}
