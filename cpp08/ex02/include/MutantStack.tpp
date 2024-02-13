/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:08:11 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 12:14:18 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP
#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack(void) {
	m_container = NULL;
    m_size = 0;
}
     
template <typename T>
MutantStack<T>::~MutantStack() {
	// if (this->m_arr != NULL)
	// 	delete [] this->m_arr; // this needed??
	this->m_container = NULL; 
}

template <typename T> // copy constructor
MutantStack<T>::MutantStack(const MutantStack &src) : m_container(NULL) {
	this->m_container = new T[this->m_size];
	for (size_t i = 0; i < this->m_size; i++)
		this->m_container[i] = src.m_container[i];
}
        
template <typename T> // assignement
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
	if (this->m_container != NULL)
		delete [] this->m_container;
	this->m_size = src.m_size;
	this->m_container = new T[this->m_size];
	for (size_t i = 0; i < this->m_size; i++)
		this->m_container[i] = src.m_container[i];
	return (*this);
}



#endif