/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:05:17 by siyang            #+#    #+#             */
/*   Updated: 2023/07/26 15:41:36 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ';';
    std::cout << "total:" << Account::getTotalAmount() << ';';
    std::cout << "deposits:" << Account::getNbDeposits() << ';';
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

Account::Account( int initial_deposit )
    : _accountIndex(Account::getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;

    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    _nbDeposits++;
    p_amount = _amount;
    _amount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    std::cout << "deposit:" << deposit << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    p_amount = _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t time;
    std::tm* localTime;
    char timeString[sizeof("[yyyymmdd_hhmmss]")];

    time = std::time(NULL);
    localTime = std::localtime(&time);
    std::strftime(timeString, sizeof(timeString), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << timeString << ' ';
}
