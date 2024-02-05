/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:14 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 12:38:00 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
    • swap: Swaps the values of two given arguments. Does not return anything.
    • min: Compares the two values passed in its arguments and returns the smallest
    one. If the two of them are equal, then it returns the second one.
    • max: Compares the two values passed in its arguments and returns the greatest one.
    If the two of them are equal, then it returns the second one.
*/

template <typename T> void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T> T max(T a, T b)
{
    return (a > b) ? a : b;
}


#endif
