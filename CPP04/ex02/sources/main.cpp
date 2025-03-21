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

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    std::cout << "\n----------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                      Abastract class"  << std::endl;
    std::cout << "----------------------------------------------------------"  << std::endl;
    {   
        std::cout << FORM << "\n✅ #1 Create a Dog class from AAnimal class\n" << RESET << std::endl;
        const AAnimal* j = new Dog();
        
        std::cout << FORM << "\n✅ #2 Destructors\n" << RESET << std::endl;
        delete j;
        
        std::cout << FORM << "\n❌ #3 Cannot create AAnimal class\n" << RESET << std::endl;
        // const AAnimal* a = new AAnimal(); 
        // delete a;
    }   
    return 0;
}