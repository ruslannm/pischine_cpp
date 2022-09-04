#include "Account.hpp"
#include <iostream>
#include <time.h>
#include <iomanip>

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
};

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
};

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
};

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
};

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return;
};


Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
};

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	return;
};

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
};

int Account::checkAmount(void) const
{
	return _amount;
};

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
	return;
};

int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int    Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	struct tm *localTime;
	time_t t;

	t = time(NULL);
	localTime = localtime(&t);
	std::cout << std::setfill('0') << "[" << localTime->tm_year + 1900;
	std::cout << std::setw(2) << localTime->tm_mon + 1;
	std::cout << std::setw(2) << localTime->tm_mday << "_";
	std::cout << std::setw(2) << localTime->tm_hour;
	std::cout << std::setw(2) << localTime->tm_min;
	std::cout << std::setw(2) << localTime->tm_sec << "] ";
	return;
};
