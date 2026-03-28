#include "../includes/Account.hpp"
#include <iostream>
#include <ctime> 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if(withdrawal <= _amount)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;

		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{   
		std::cout << "withdrawal:refused" << std::endl; 
		return false;
	}
}

int		Account::checkAmount( void )   const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t		rawtime;
	std::tm			timeinfo;

	rawtime = std::time(NULL);
	timeinfo = *std::localtime( &rawtime );
	
	char buffer[20]; 
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", &timeinfo); 	
	std::cout << buffer << " ";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0; 
	_nbWithdrawals = 0;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	_nbAccounts--;
	
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	
	_totalAmount -= _amount;
}

/*
./account >> check.log
sed 's/^[^]]*] //' check.log > file1.log     
sed 's/^[^]]*] //' 19920104_091532.log > file2.log
diff file1.log file2.log
*/