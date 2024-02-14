/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:34:51 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/14 11:17:03 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void);
        ~MutantStack();
        MutantStack(const MutantStack &src); // copy constructor
        MutantStack& operator=(const MutantStack &csrc); // assignment

        typedef typename std::deque<T>::iterator iterator;
        iterator begin();
        iterator end();
};


#include "MutantStack.tpp"


#endif