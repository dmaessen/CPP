/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:53:31 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 14:08:45 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_HPP
#define INIT_HPP
#include <iostream>
#include <cstdint>
#include <stdint.h>

typedef struct s_data
{
    int i;
    char c;
} Data;

class Init
{
    private:
        
    public:
        Init(void);
        ~Init(void);
        Init(const Init &copy); // copy constructor
        Init& operator=(const Init &copy); // assignment
        
        //static void convert(Data* d);
};

#endif