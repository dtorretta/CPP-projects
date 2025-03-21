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

#include "../includes/ClapTrap.hpp"
#include <iostream>

int main() {

    std::cout << "\n*** TESTING THE DEFAULT CONSTRUCTOR & THE COPY ASSIGNMENT OPERATOR ***\n" << std::endl;

    ClapTrap A; //default name Rei
    ClapTrap B("Shinji");
    A = B;

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
        
    A.attack("Lilith");
    A.takeDamage(3);
    A.beRepaired(4);
    A.takeDamage(10);//dead!
    A.attack("Adam"); //no more HP. cant attack.
    A.beRepaired(3); //no more HP. cant be repaired.
    
    std::cout << "\nA: " << std::endl
    << "    name: " << A.get_name() << std::endl
    << "    health: " << A.get_hitpoints() << std::endl
    << "    energy: " << A.get_energypoints() << std::endl
    << "    damage: " << A.get_attackdamage() << std::endl;
    
    
    std::cout << "\n*** TESTING THE NAME CONSTRUCTOR & THE COPY ASSIGNMENT OPERATOR ***\n" << std::endl;
    ClapTrap D("Asuka");
    ClapTrap C(D);
    
    std::cout << "\nC: " << std::endl
    << "    name: " << C.get_name() << std::endl
    << "    health: " << C.get_hitpoints() << std::endl
    << "    energy: " << C.get_energypoints() << std::endl
    << "    damage: " << C.get_attackdamage() << std::endl;
    
    std::cout << "\nD: " << std::endl
    << "    name: " << D.get_name() << std::endl
    << "    health: " << D.get_hitpoints() << std::endl
    << "    energy: " << D.get_energypoints() << std::endl
    << "    damage: " << D.get_attackdamage() << "\n" << std::endl;
    
    for(int i = 0; i < 10; i++)
    {
        C.attack("Lilith");
    } //c has no more energy
    C.attack("Lilith"); //no more enery points. cant attack.
    C.beRepaired(3); //no more enery points. cant be repaired.
    
    std::cout << "\nC: " << std::endl
    << "    name: " << C.get_name() << std::endl
    << "    health: " << C.get_hitpoints() << std::endl
    << "    energy: " << C.get_energypoints() << std::endl
    << "    damage: " << C.get_attackdamage() << "\n" << std::endl;
    
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