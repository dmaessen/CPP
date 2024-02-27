/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:09:50 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/27 21:30:52 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array(void) {
	m_arr = NULL;
	m_size = 0;
	// std::cout << "Default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) { 
	m_arr = new T[n]();
	m_size = n;
	// std::cout << "Default constructor called\n";
} 
        
template <typename T>
Array<T>::~Array() {
	if (this->m_arr != NULL)
		delete [] this->m_arr;
	this->m_arr = NULL;
	// std::cout << "Destructor called\n";
}

template <typename T>
Array<T>::Array(const Array &src) : m_arr(NULL), m_size(src.m_size) {
	// std::cout << "Copy constructor called\n";
	this->m_arr = new T[this->m_size];
	for (size_t i = 0; i < this->m_size; i++)
		this->m_arr[i] = src.m_arr[i];
}
        
template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
	//std::cout << "Copy assignement operator called\n";
	if (this->m_arr != NULL)
		delete [] this->m_arr;
	this->m_size = src.m_size;
	this->m_arr = new T[this->m_size];
	for (size_t i = 0; i < this->m_size; i++)
		this->m_arr[i] = src.m_arr[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t i) {
	if (i >= this->m_size)
		throw (Array<T>::OutOfBoundException());
	return this->m_arr[i];
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
	if (i >= this->m_size)
		throw (Array<T>::OutOfBoundException());
	return this->m_arr[i];
}

template <typename T>
const char * Array<T>::OutOfBoundException::what() const throw() {
    return ("Array index out of bound.\n");
}

template <typename T>
size_t Array<T>::size(void) const {
    return this->m_size;
}

template <typename T>
std::ostream	&operator<<(std::ostream &out, const Array<T> &src)
{
	out << "[";
	for (size_t i = 0; i < src.size(); i++)
	{
		out << src[i];
		if (i < src.size() - 1)
			out << ", ";
	}
	out << "]";
	return (out);
}

#endif