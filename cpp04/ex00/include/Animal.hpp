/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:48 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 15:43:27 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &copy); // copy constructor
        Animal& operator=(const Animal &copy); // assignment
        ~Animal(void);

        std::string getType( void ) const;
		void setType( std::string input );
        
        void makeSound();
        
};

#endif