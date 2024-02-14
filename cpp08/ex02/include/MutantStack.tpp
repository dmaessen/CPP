/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:08:11 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/14 11:17:11 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP
#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	// std::cout << "Default constructor called\n";
}
     
template <typename T>
MutantStack<T>::~MutantStack() {
	// std::cout << "Destructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
	// std::cout << "Copy constructor called\n";
}
        
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
	//std::cout << "Copy assignement operator called\n";
	if (this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin()); // c for container
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}


#endif