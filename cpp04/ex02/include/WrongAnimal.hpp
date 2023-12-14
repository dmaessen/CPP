/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:37:48 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/14 12:50:24 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &copy); // copy constructor
        WrongAnimal& operator=(const WrongAnimal &copy); // assignment
        virtual ~WrongAnimal(void);

        std::string getType( void ) const;
		void setType( std::string input );
        
        void makeSound( void ) const ;
        
};

#endif