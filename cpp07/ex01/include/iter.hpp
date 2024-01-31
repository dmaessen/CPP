/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:22:03 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/31 14:35:06 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T> void print(T item) 
{
    std::cout << item <<'\n';
}

template <typename T, typename Func> void iter(T* arr, size_t len, Func p)
{
    for (size_t i = 0; i < len; i++)
        p(arr[i]);
}

#endif