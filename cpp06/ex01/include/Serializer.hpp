/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:35 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 16:16:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

typedef struct s_data
{
    int i; // or something else?? no clue
    char c;
} Data;

class Serializer
{
    private:
        
    public:
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer &copy); // copy constructor
        Serializer& operator=(const Serializer &copy); // assignment
        
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif