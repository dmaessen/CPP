/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:39 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 15:12:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

// can we do everything in here for this template step??
template <class T>
class Array
{
    private:
        T* arr; // or T arr[] ??
        
    public:
        Array(void) { arr = new[]; } // creates an empty arr
        Array(unsigned int n) { arr[n] = new[]; } // does this work?? //creates an arr of n elements
        ~Array() {delete arr;}
        Array(const Array &copy); // copy constructor -- TO DO
        Array& operator=(const Array &copy); // assignment -- TO DO

        T size() {
            for (int i = 0; arr[i] != '\0'; i++)
            return i;
        } // returns the nb of elements in the arr
};



#endif