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

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                           Assigment Operator"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    {
        std::cout << FORM << "\n✅ #1 Create object A with ClapTrap Default constructor\n" << RESET << std::endl;
        ClapTrap A; //default name Rei
        
        std::cout << FORM << "\n✅ #2 Create object B with ClapTrap Name constructor\n" << RESET << std::endl;
        ClapTrap B("Shinji");
        
        std::cout << FORM << "\n✅ #3 Make a copy with the Assigment Operator\n" << RESET << std::endl;
        A = B;
    
        std::cout << FORM << "\n✅ #4 Print object A's stats\n" << RESET << std::endl;
        std::cout << "    name: " << A.get_name() << std::endl
            << "    health: " << A.get_hitpoints() << std::endl
            << "    energy: " << A.get_energypoints() << std::endl
            << "    damage: " << A.get_attackdamage() << std::endl;
            
        std::cout << FORM << "\n✅ #5 Print object B's stats\n" << RESET << std::endl;
        std::cout << "    name: " << B.get_name() << std::endl
            << "    health: " << B.get_hitpoints() << std::endl
            << "    energy: " << B.get_energypoints() << std::endl
            << "    damage: " << B.get_attackdamage() << std::endl;
            
        std::cout << FORM << "\n✅ #6 Test object A's 0HP\n" << RESET << std::endl;
        A.attack("Lilith");
        A.takeDamage(3);
        A.beRepaired(4);
        A.takeDamage(10);//dead!
        A.attack("Adam"); //no more HP. cant attack.
        A.beRepaired(3); //no more HP. cant be repaired.
        
        std::cout << FORM << "\n✅ #4 Print object A's stats\n" << RESET << std::endl;
        std::cout << "    name: " << A.get_name() << std::endl
        << "    health: " << A.get_hitpoints() << std::endl
        << "    energy: " << A.get_energypoints() << std::endl
        << "    damage: " << A.get_attackdamage() << std::endl;
        
        std::cout << FORM << "\n✅ #5 Drestructors\n" << RESET << std::endl;
    }
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                             Copy Operator"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    {
        std::cout << FORM << "\n✅ #1 Create object D with ClapTrap Default constructor\n" << RESET << std::endl;
        ClapTrap D("Asuka");
        
        std::cout << FORM << "\n✅ #2 create object C with the copy operator\n" << RESET << std::endl;
        ClapTrap C(D);
        
        std::cout << FORM << "\n✅ #3 Print object C's stats\n" << RESET << std::endl;
        std::cout << "    name: " << C.get_name() << std::endl
        << "    health: " << C.get_hitpoints() << std::endl
        << "    energy: " << C.get_energypoints() << std::endl
        << "    damage: " << C.get_attackdamage() << std::endl;
        
        std::cout << FORM << "\n✅ #4 Print object D's stats\n" << RESET << std::endl;
        std::cout << "    name: " << D.get_name() << std::endl
        << "    health: " << D.get_hitpoints() << std::endl
        << "    energy: " << D.get_energypoints() << std::endl
        << "    damage: " << D.get_attackdamage() << std::endl;
        
        std::cout << FORM << "\n✅ #5 Test object C's 0 EnergyPoints\n" << RESET << std::endl;
        for(int i = 0; i < 10; i++)
        {
            C.attack("Lilith");
        } //c has no more energy
        C.attack("Lilith"); //no more enery points. cant attack.
        C.beRepaired(3); //no more enery points. cant be repaired.
        
        std::cout << FORM << "\n✅ #6 Print object C's stats\n" << RESET << std::endl;
        std::cout << "    name: " << C.get_name() << std::endl
        << "    health: " << C.get_hitpoints() << std::endl
        << "    energy: " << C.get_energypoints() << std::endl
        << "    damage: " << C.get_attackdamage() << std::endl;
        
        std::cout << FORM << "\n✅ #7 Drestructors\n" << RESET << std::endl;
    }
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