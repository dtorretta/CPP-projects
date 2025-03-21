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
#include <iostream>

int main() {
    std::cout << "\n*** ScavTrap ***" << std::endl;
    ScavTrap    A("Shinji");
    ScavTrap    B; //default name Lilith

    std::cout << "\nA: " << std::endl
    << "    name: " << A.get_name() << std::endl
    << "    health: " << A.get_hitpoints() << std::endl
    << "    energy: " << A.get_energypoints() << std::endl
    << "    damage: " << A.get_attackdamage() << std::endl;
    
    std::cout << "\nB: " << std::endl
    << "    name: " << B.get_name() << std::endl
    << "    health: " << B.get_hitpoints() << std::endl
    << "    energy: " << B.get_energypoints() << std::endl
    << "    damage: " << B.get_attackdamage() << "\n" << std::endl;
        
    A.guardGate();
    std::cout << std::endl;
     
     
    for (int i = 0; i < 5; i++) 
    {
        A.attack("Lilith");
        B.takeDamage(A.get_attackdamage());;
        
    } //Lilith is dead
    std::cout << std::endl;
    
    B.guardGate(); //B is dead, cant guard the door.
    
    std::cout << "\nA: " << std::endl
    << "    name: " << A.get_name() << std::endl
    << "    health: " << A.get_hitpoints() << std::endl
    << "    energy: " << A.get_energypoints() << std::endl
    << "    damage: " << A.get_attackdamage() << std::endl;
    
    std::cout << "\nB: " << std::endl
    << "    name: " << B.get_name() << std::endl
    << "    health: " << B.get_hitpoints() << std::endl
    << "    energy: " << B.get_energypoints() << std::endl
    << "    damage: " << B.get_attackdamage() << "\n" << std::endl;
       
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