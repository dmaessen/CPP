/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:09 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/13 16:08:45 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
Account::Account()
{
	int nb_acc = getNbAccounts();

	_nbAccounts += 1;
	_accountIndex = nb_acc;
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// just init here right?? nothing to write?
}

Account::Account( int initial_deposit )
{
    int nb_acc = getNbAccounts();
	
	_nbAccounts += 1;
	_accountIndex = nb_acc;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << '\n';
}

Account::~Account()
{
	// int nb_acc = getNbAccounts();
	// calculation needs to be dif here: amount + deposit - withd
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << '\n';
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
    //this displays on one line the total info of all 8 acc
}

void	Account::makeDeposit( int deposit )
{
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	
}

int		Account::checkAmount( void ) const 
{
	
}

void	Account::displayStatus( void ) const {
	
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    
    std::cout << "[" << ltm->tm_year << 1+ltm->tm_mon << ltm->tm_mday;
    std::cout << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
    //je crois [annee-mois-jour_heure-min-sec]
}
