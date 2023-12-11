/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:57 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 11:56:21 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal 
{
    private:
        Brain* m_brain;

    public:
        Cat(void);
        Cat(const Cat &copy); // copy constructor
        Cat& operator=(const Cat &copy); // assignment
        ~Cat(void);

        Brain& getBrain( void ) const;
		void setBrain( Brain* input );

        void makeSound( void ) const ;

};

#endif