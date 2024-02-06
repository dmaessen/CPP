/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:27:26 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/06 11:09:09 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> 
int easyfind(T a, int nb) 
{
    // find i within the vector of ints
    std::vector<int>::iterator ptr; 
    ptr = std::find(a.begin(), a.end(), nb);
    if (ptr != a.end())
        return 0;
    return -1;
}

#endif