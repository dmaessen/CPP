/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:53 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 11:56:16 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal 
{
    private:
        Brain* m_brain;

    public:
        Dog(void);
        Dog(const Dog &copy); // copy constructor
        Dog& operator=(const Dog &copy); // assignment
        ~Dog(void);

        Brain& getBrain( void ) const;
		void setBrain( Brain* input );

        void makeSound( void ) const ;
};

#endif