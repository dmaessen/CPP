/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:43:57 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/07 14:57:51 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal 
{
    protected:

    public:
        WrongCat(void);
        WrongCat(const WrongCat &copy); // copy constructor
        WrongCat& operator=(const WrongCat &copy); // assignment
        ~WrongCat(void);

        void makeSound( void ) const ;
};

#endif