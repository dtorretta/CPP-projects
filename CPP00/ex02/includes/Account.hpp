// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;
	
	static int	getNbAccounts( void ); //ok
	static int	getTotalAmount( void ); //ok
	static int	getNbDeposits( void ); //ok
	static int	getNbWithdrawals( void ); //ok
	static void	displayAccountsInfos( void ); //ok

	Account( int initial_deposit ); //ok
	
	//debe mostrar un mensaje indicando que la cuenta se cerró.
	~Account( void ); 

	void	makeDeposit( int deposit ); //ok
	bool	makeWithdrawal( int withdrawal ); //ok
	int		checkAmount( void ) const; //ok
	void	displayStatus( void ) const; //ok


private:
	//inicializarlos a 0 como variables globales
	//estas son variables staticas Son variables compartidas entre todos los nodos
	//existen una sola vez para toda la clase.
	static int	_nbAccounts; //ok
	static int	_totalAmount; //ok
	static int	_totalNbDeposits; //ok
	static int	_totalNbWithdrawals; //ok

	static void	_displayTimestamp( void );

	//el contructor trabaja con esto
	//de forma predeterminada las inicie en 0 el conructor sin parametro pero creo que no haria falta
	//estas son variables de instacia --> varian para cada objeto (nodo) que cree
	//se inicializan dentro del constructor o directamente en su declaración si es necesario.
	int				_accountIndex; //ok 
	int				_amount; //ok
	int				_nbDeposits; //ok
	int				_nbWithdrawals; //ok

	Account( void ); //ok
	//si bien ya hay un constructor account con paramentros, dejar este aca perie que se pueda crear una instacia usando los valores predeterminados
	//tambien sirve para crear objetos de Account y luego configurarlos más tarde con algún método.
	//puedo usarlo para incializar variables que NO sean STATIC 
};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
