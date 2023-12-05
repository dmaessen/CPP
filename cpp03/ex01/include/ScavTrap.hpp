/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:18:35 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/05 11:18:36 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:

    public:
        ScavTrap(std::string name); // default constructor
        ScavTrap(const ScavTrap &copy); // copy constructor
        ScavTrap& operator=(const ScavTrap &copy); // assignment
		~ScavTrap(void);

        void attack(const std::string& target);

		void guardGate();
};

#endif