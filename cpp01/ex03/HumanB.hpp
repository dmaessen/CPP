/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:03:16 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/16 14:00:36 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string m_name;
        Weapon*     m_weapon;

    public:
        HumanB(std::string name);
        ~HumanB(void);
    
        void		setName(std::string input);
        std::string	getName() const;
        void        setWeapon(Weapon& w);
        Weapon      getWeapon() const;

        void        attack();
};

#endif