/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:02:32 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain(void);
        Brain(const Brain &copy);
        Brain& operator=(const Brain &copy);
        ~Brain(void);

        std::string getIdeas( void ) const; // still to write them
		void setIdeas( std::string input ); // still to write
        
};

#endif