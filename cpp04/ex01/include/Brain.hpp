/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:02:32 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/11 11:37:11 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include "Animal.hpp"

class Brain
{
    private:
        std::string m_ideas[100];

    public:
        Brain(void);
        Brain(const Brain &copy);
        Brain& operator=(const Brain &copy);
        ~Brain(void);

		void setIdeas( std::string input, int i );
        std::string getIdeas( int i ) const;
};

#endif