/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:53 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 14:52:16 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal 
{
    protected:

    public:
        Dog(void);
        Dog(const Dog &copy); // copy constructor
        Dog& operator=(const Dog &copy); // assignment
        ~Dog(void);

        void makeSound( void ) const ;
};

#endif