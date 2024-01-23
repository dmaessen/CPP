/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:35 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 12:32:58 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    private:

        
    public:
        ScalarConverter(void); // needed??
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &copy); // assignment
        
        static void converter(std::string input); // takes as param a string representation of c++ literal
};

#endif