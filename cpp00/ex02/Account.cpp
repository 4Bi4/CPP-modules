/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:39:48 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/11 22:37:27 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	if (initial_deposit < 0)
		_amount = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << initial_deposit << ";" << "created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) {return (_nbAccounts);}

int	Account::getTotalAmount( void ) {return (_totalAmount);}

int	Account::getNbDeposits( void ) {return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void ) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;

	if (deposit < 0)
		return ;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= 0)
		return (false);
	if (withdrawal > _amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
			<< std::endl;
		return (false);
	}
	int	p_amount = this->_amount;
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
	std::tm *tm = std::localtime(&t);

	// Format: [YYYYMMDD_HHMMSS]
	std::cout << '['
		<< (tm->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (tm->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << tm->tm_mday
		<< '_'
		<< std::setw(2) << std::setfill('0') << tm->tm_hour
		<< std::setw(2) << std::setfill('0') << tm->tm_min
		<< std::setw(2) << std::setfill('0') << tm->tm_sec
		<< "] ";
}
