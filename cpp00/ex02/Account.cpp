#include "Account.hpp"

int	::Account::_nbAccounts = 0;
int	::Account::_totalAmount = 0;
int	::Account::_totalNbDeposits = 0;
int	::Account::_totalNbWithdrawals = 0;

Account(int initial_deposit) :	_accountIndex(::Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	::Account::_nbAccounts ++;
	this->makeDeposit(initial_deposit);
	std::cout << "TODO: LOG CON." << std::endl;
}

~Account(void)
{
	::Account::_nbAccounts --;
	std::cout << "TODO: LOG DES." << std::endl;
}

void	makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits ++;
	::Account::_totalAmount += deposit;
	::Account::_totalNbDeposits ++;
}

bool	makeWithdrawal(int withdrawal)
{
}

int		checkAmount(void) const
{
}

void	displayStatus(void) const
{
}

int	getNbAccounts(void)
{
	return (::Account::_nbAccounts);
}

int	getTotalAmount(void)
{
	return (::Account::_totalAmount);
}

int	getNbDeposits(void)
{
	return (::Account::_totalNbDeposits);
}

int	getNbWithdrawals(void)
{
	return (::Account::_totalNbWithdrawals);
}

void	displayAccountsInfos(void)
{
}

void	_displayTimestamp(void)
{
}

Account(void)
{}
