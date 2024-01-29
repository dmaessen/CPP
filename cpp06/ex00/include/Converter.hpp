/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:35 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/29 14:11:34 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include "ScalarConverter.hpp"

class Converter // make this non instantiable
{
    private:

        
    public:
        // Converter(void); // needed??
        // ~Converter(void);
        // Converter(const Converter &copy); // copy constructor
        // Converter& operator=(const Converter &copy); // assignment
        
        void conv_char(std::string input); // make this static ??
        void conv_int(std::string input);  // make this static ??
        void conv_float(std::string input);  // make this static ??
        void conv_double(std::string input);  // make this static ??
};

#endif