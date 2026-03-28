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
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 0"  << std::endl;
    std::cout << "                     from subject"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        std::cout << FORM << "\n✅ #1 Animal\n" << RESET << std::endl;
        const Animal* meta = new Animal();
        meta->makeSound();
        delete meta;
         
        std::cout << FORM << "\n✅ #2 Dog\n" << RESET << std::endl;
        const Animal* j = new Dog();
        std::cout << ORANGE << "Type: " << RESET << j->getType() << std::endl;
        j->makeSound();
        delete j;
        
        std::cout << FORM << "\n✅ #3 Cat\n" << RESET << std::endl;
        const Animal* i = new Cat();
        std::cout << GREEN << "Type: " << RESET << i->getType() << std::endl;
        i->makeSound();
        delete i;
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                WrongAnimal and WrongCat"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        std::cout << FORM << "\n✅ #1 Create a WrongAnimal object from WrongAnimal class\n" << RESET << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        meta->makeSound();
        
        std::cout << FORM << "\n✅ #2 Create a WrongCat object from WrongAnimal class\n" << RESET << std::endl;
        const WrongAnimal* i = new WrongCat();
        std::cout << GREEN << "Type: " << RESET << i->getType() << std::endl;
        i->makeSound();
        delete i;
        delete meta;
    }
    return 0;
}
