/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:11:47 by jvigny            #+#    #+#             */
/*   Updated: 2023/11/30 17:25:51 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t now (std::time(NULL));
	std::tm *time = localtime(&now);

	std::cout << "[" << time->tm_year + 1900 << time->tm_mon + 1 << time->tm_mday << "_" \
	<< time->tm_hour << time->tm_min << time->tm_sec << "]";
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::getNbAccounts();
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit << ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() \
		<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" \
		<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposits:" \
		<< deposit << ";amount:" << (this->checkAmount() + deposit) <<";nb_deposits:" << this->_nbDeposits<< std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:";
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout <<"refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << this->checkAmount() <<";nb_withdrawals:" << this->_nbDeposits<< std::endl;
	return true;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}