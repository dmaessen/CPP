/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:12:15 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 15:55:35 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
    private:
        std::string m_type;
        Weapon(void);

    public:
        Weapon(std::string input);
        ~Weapon(void);
    
        void		setType(std::string input);
        std::string	getType() const;
};

#endif