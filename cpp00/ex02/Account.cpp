/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:09 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/14 11:35:51 by dmaessen         ###   ########.fr       */
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
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount \
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	_amount -= withdrawal;
	if (checkAmount() == -1)
	{
		_amount += withdrawal;
		std::cout << "refused" << '\n';
		return false;
	}
	else
	{
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
	}
	return true;
} 

int		Account::checkAmount( void ) const 
{
	if (_amount < 0)
		return -1;
	else
		return 0;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" \
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = time(0);
    std::tm *ltm = localtime(&now);
    
    std::cout << "[" << 1900+ltm->tm_year << 1+ltm->tm_mon << ltm->tm_mday;
    std::cout << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
}
