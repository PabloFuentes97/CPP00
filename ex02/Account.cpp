#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	printTimeStr(void)
{
	time_t		curr_time;
	struct tm	*time_info;
	char		buffer[1000];

	time(&curr_time);
	time_info = localtime(&curr_time);
	strftime(buffer, 1000, "[%Y%m%e_%H%M%S]", time_info);
	std::cout << buffer;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
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
	printTimeStr();
	std::cout << " " << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" 
		<< "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	printTimeStr();
	std::cout << " " << "index:" << getNbAccounts() << ";" << "amount:" << initial_deposit << ";"
		<< "created" << std::endl;
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
}
Account::~Account( void )
{
	printTimeStr();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
	<< "closed" << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	printTimeStr();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";" << "deposit:";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << deposit << ";" << "amount:" << this->_amount << ";" << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	printTimeStr();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";" << "withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount-= withdrawal;
	std::cout << withdrawal << ";" << "amount:" << this->_amount << ";" << "nb_withdrawals:" 
		<< this->_nbWithdrawals << std::endl;
	return (1);
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
void	Account::displayStatus( void ) const
{
	printTimeStr();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" 
		<< "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
