/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:55:05 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 16:01:15 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string m_name;
        Weapon m_weapon;

    public:
        HumanA(std::string name, Weapon& w); // is this correct??
        ~HumanA(void);
    
        void		setName(std::string input);
        void		setWeapon(std::string input);
        std::string	getName() const;
        // std::string	getWeapon() const;

        void        attack();
};

#endif