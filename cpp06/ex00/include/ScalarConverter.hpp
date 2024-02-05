/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:55:35 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 12:30:25 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy); // copy constructor
        ScalarConverter& operator=(const ScalarConverter &copy); // assignment
        
    public:
        static void convert(std::string input);
};

#endif