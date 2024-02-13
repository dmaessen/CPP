/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:34:51 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 14:06:47 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T>
class MutantStack
{
    private:
        T* m_container; // or whatever
        size_t m_size; // needed??

    public:
        MutantStack(void);
        //MutantStack(unsigned int n);
        ~MutantStack();
        MutantStack(const MutantStack &src); // copy constructor
        MutantStack& operator=(const MutantStack &csrc); // assignment

        // TO IMPLEMENT:
        // ITERATORS for begin();
        // ITERATORS for end();
};

#include "MutantStack.tpp"


#endif