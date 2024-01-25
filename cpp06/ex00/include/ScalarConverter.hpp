/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:35 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/25 14:35:03 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    private:

        
    public:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &copy); // assignment
        
        static void convert(std::string input); // takes as param a string representation of c++ literal
};

#endif