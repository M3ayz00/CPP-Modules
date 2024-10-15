/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:28:22 by msaadidi          #+#    #+#             */
/*   Updated: 2024/10/15 16:44:27 by msaadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

std::string	getTimeStamp(void)
{
	char		buffer[20];
	std::time_t now = std::time(NULL);
	tm			*timeInfo = std::localtime(&now);

	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeInfo);
	return (std::string(buffer));
}

int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << getTimeStamp() << "accounts:" << _nbAccounts << ";total" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = _nbAccounts;
	std::cout << getTimeStamp() << "index:" << _accountIndex << ";amount:" << _amount << ";created"<< std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	std::cout << getTimeStamp() << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayStatus( void ) const
{
	std::cout << getTimeStamp() << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (_amount > 0);
}

void	Account::makeDeposit( int deposit )
{
	std::cout << getTimeStamp() << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << getTimeStamp() << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (checkAmount() && withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
		std::cout << "refused" << std::endl;
	return (false);
}
