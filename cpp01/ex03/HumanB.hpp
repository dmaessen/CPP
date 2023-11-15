/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:03:16 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/15 15:07:08 by dmaessen         ###   ########.fr       */
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
        Weapon  m_weapon;

    public:
        HumanB(void); // is this correct??
        ~HumanB(void);
    
        void		setName(std::string input);
        void		setWeapon(std::string input);
        std::string	getName() const;
        std::string	getWeapon() const;

        void        attack();
};

#endif