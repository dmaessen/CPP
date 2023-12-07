/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:57 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 15:01:42 by dmaessen         ###   ########.fr       */
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
        Brain* _brain;

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