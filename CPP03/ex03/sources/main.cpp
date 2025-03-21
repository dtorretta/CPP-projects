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

#include "../includes/DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                              DiamondTrap "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 Create object A with DiamondTrap Name constructor\n" << RESET << std::endl;
    DiamondTrap  A("Asuka");
    std::cout << FORM << "\n✅ #2 Create object B with DiamondTrap Default constructor\n" << RESET << std::endl;
    DiamondTrap  B; //Default_clap_name

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
    
    /*
    como takeDamage y beRepaired son de la clase ClapTrap,cuawndo vuevlo a imprmir lo valores, estos no quedan actuaizados porque estan tomando 
    los de FragTrap.  si quisiera arreglarlo deberia especificar en DiamondTrap que use las funciones de FragTrap 
    y en FragTrap redefinir esas funciones para que modifiquen los valores almacenados en esa clase
    
    */
   std::cout << FORM << "\n✅ #5 Test previous methods\n" << RESET << std::endl;
    B.attack("Asuka");
    A.takeDamage(B.get_attackdamage()); // 100 - 30 = 70
    A.beRepaired(10); //100 - 30 + 10    = 80  
    B.guardGate();
    A.highFivesGuys();
    
    std::cout << FORM << "\n✅ #6 test new method whoAmI\n" << RESET << std::endl;  
    A.whoAmI();
    B.whoAmI();
    
    std::cout << FORM << "\n✅ #7 Drestructors\n" << RESET << std::endl;
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