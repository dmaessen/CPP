/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:57 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/12 14:46:20 by dmaessen         ###   ########.fr       */
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

        std::string getType( void ) const;
		void setType( std::string input );

};

#endif