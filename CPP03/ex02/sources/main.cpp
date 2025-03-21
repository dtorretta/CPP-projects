/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:58:02 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:58:02 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include <iostream>

int main() {  
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                               FragTrap "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 Create object A with FragTrap Default constructor\n" << RESET << std::endl;
    FragTrap    A; //default name Shinji
    std::cout << FORM << "\n✅ #2 Create object B with FragTrap Name constructor\n" << RESET << std::endl;
    FragTrap    B("Lilith");

    std::cout << FORM << "\n✅ #3 Print object A's stats\n" << RESET << std::endl;
    std::cout << "    name: " << A.get_name() << std::endl
    << "    health: " << A.get_hitpoints() << std::endl
    << "    energy: " << A.get_energypoints() << std::endl
    << "    damage: " << A.get_attackdamage() << std::endl;
    
    std::cout << FORM << "\n✅ #4 Print object B's stats\n" << RESET << std::endl;
    std::cout << "    name: " << B.get_name() << std::endl
    << "    health: " << B.get_hitpoints() << std::endl
    << "    energy: " << B.get_energypoints() << std::endl
    << "    damage: " << B.get_attackdamage() << std::endl;
      
    std::cout << FORM << "\n✅ #5 Makes object B 0HP\n" << RESET << std::endl; 
    B.attack("Shinji");
    A.takeDamage(B.get_attackdamage()); 
    A.beRepaired(10);
    std::cout << std::endl;
    for(int i = 0; i < 4; i++)
    {
        A.attack("Lilith");
        B.takeDamage(A.get_attackdamage()); 
    } //lilith is dead
    
    std::cout << FORM << "\n✅ #6 test new method highFivesGuys\n" << RESET << std::endl;  
    B.highFivesGuys();
    A.highFivesGuys();
       
    std::cout << FORM << "\n✅ #7 Print object A's stats\n" << RESET << std::endl;
    std::cout << "    name: " << A.get_name() << std::endl
    << "    health: " << A.get_hitpoints() << std::endl
    << "    energy: " << A.get_energypoints() << std::endl
    << "    damage: " << A.get_attackdamage() << std::endl;
    
    std::cout << FORM << "\n✅ #8 Print object B's stats\n" << RESET << std::endl;
    std::cout << "    name: " << B.get_name() << std::endl
    << "    health: " << B.get_hitpoints() << std::endl
    << "    energy: " << B.get_energypoints() << std::endl
    << "    damage: " << B.get_attackdamage() << std::endl;    
    
    std::cout << FORM << "\n✅ #9 Drestructors\n" << RESET << std::endl;
    return 0;
}


/*
A = B;
El operador =  no crea un nuevo objeto A. 
En cambio, reemplaza los valores actuales de A con los de B. 
Como estamos en una asignación, no se crea un nuevo objeto y el destructor de A no se llama en este momento

Aunque ambos objetos (A y B) tienen el mismo nombre después de la asignación ("Shinji"), son dos instancias distintas de la clase ClapTrap.

1) ¿Si bien C y D comparten el mismo nombre, son copias y por ende las modificaciones de uno no se verán reflejadas en el otro?
Correcto.

2) Al final, ¿habrán dos llamadas al destructor, una por D y otra por C?
Sí, también es correcto.

*/