/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:09 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/09 15:59:04 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

static int	getNbAccounts( void )
{
    
    
}

static int	getTotalAmount( void )
{
    
}

static int	getNbDeposits( void )
{
    
}

static int	getNbWithdrawals( void )
{
    
}

static void	displayAccountsInfos( void )
{
    for (int i = 0; i < 8; i++)
    {
        _displayTimestamp();
        std::cout << "index:" << i <<;
        
    }
}

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;

static void	_displayTimestamp( void )
{
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    
    std::cout << "[" << ltm->tm_year << 1+ltm->tm_mon << ltm->tm_mday;
    std::cout << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
    //je crois [annee-mois-jour_heure-min-sec]
}
