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

#define FORM "\033[4m"

#include <iostream>

int main()
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 0"  << std::endl;
    std::cout << "                     from subject"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {   
        std::cout << FORM << "\n✅ #1 Constructors\n" << RESET << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << FORM << "\n✅ #2 Destructors\n" << RESET << std::endl;
        delete j; //should not create a leak
        delete i;
    }   
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "          Create and fill an array of Animal objects"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {
        int size = 4;
        Animal *arrayAnimals[size];
        
        std::cout << FORM << "\n✅ #1 Constructors\n" << RESET << std::endl;
        for(int i = 0; i <= size / 2; i++)
        {
            arrayAnimals[i] = new Dog(); //usamos new especificamente porque la consigna quiere que useamos despues delete
            std::cout << std::endl;
            arrayAnimals[size - 1] = new Cat();
            std::cout << std::endl;
            size--;
        }
        
        size = 4;
        std::cout << FORM << "\n✅ #2 Destructors\n" << RESET << std::endl;
        for(int i = 0; i < size; i++)
        {
            delete arrayAnimals[i];
            std::cout << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TETS 2"  << std::endl;
    std::cout << "           Cat deep copy with assigment operator"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    {        
        std::cout << FORM << "\n✅ #1 Create a cat1 object from Cat class\n" << RESET << std::endl;
        Cat *cat1 = new Cat();
        
        //set its ideas
        cat1->setIdea(0, "  I'm hungry");
        cat1->setIdea(1, "  I wanna play");
        cat1->setIdea(2, "  I need my box");
        
        std::cout << FORM << "\n✅ #2 Print cat1 ideas\n" << RESET << std::endl;      
        for(int i = 0; i < 3; i++)
        {
            std::cout  << i + 1 << "." << BLUE << cat1->getIdea(i) << RESET << std::endl;
        }
        
        std::cout << FORM << "\n✅ #3 create a cat2 object from Cat class\n" << RESET << std::endl;    
        Cat *cat2 = new Cat();
        
        std::cout << FORM << "\n✅ #4 Print cat2 ideas before copy assignment operator\n" << RESET << std::endl;   
        for(int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << "." << BLUE << cat2->getIdea(i) << RESET  << std::endl;
        }
        
        std::cout << FORM << "\n✅ #5 Make deep copy using the copy assigment operator\n" << RESET << std::endl;   
        *cat2 = *cat1; //deep copie
        
        std::cout << FORM << "\n✅ #6 Print cat2 ideas after copy assignment operator\n" << RESET << std::endl;   
        for(int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << "." << BLUE << cat2->getIdea(i) << RESET  << std::endl;
        }
        
        std::cout << FORM << "\n✅ #7 Call destructor\n" << RESET << std::endl;  
        delete cat1;
        delete cat2;     
    }
    std::cout << "\n----------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 3"  << std::endl;
    std::cout << "            Dog deep copy with Copy operator"  << std::endl;
    std::cout << "----------------------------------------------------------"  << std::endl;
    {
        std::cout << FORM << "\n✅ #1 Create a cat1 object from Cat class\n" << RESET << std::endl;
        Dog *dog1 = new Dog();
        
        dog1->setIdea(0, "  I'm hungry");
        dog1->setIdea(1, "  I wanna play");
        dog1->setIdea(2, "  I need a tree");
        
        std::cout << FORM << "\n✅ #2 Print dog1 ideas\n" << RESET << std::endl;         
        for(int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << "." << BLUE << dog1->getIdea(i) << RESET << std::endl;
        }
        
        std::cout << FORM << "\n✅ #3 create a dog2 object using the copy operator\n" << RESET << std::endl;    
        Dog dog2(*dog1);
        
        std::cout << FORM << "\n✅ #4 Print dog2 ideas\n" << RESET << std::endl;     
        for(int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << "." << BLUE << dog2.getIdea(i) << RESET << std::endl;
        }
        
        std::cout << FORM << "\n✅ #5 Call destructor\n" << RESET << std::endl;          
        delete dog1;
        //delete dog2; //se elimina automaticamente 
    }
    return 0;
}

/*
    como estamos usando 'new' y punteros, la memoria esta allocada en el HEAP y no en el STACK por lo que el destructor no se llama
    automaticamente y hay que de forma explicita usar DELETE
    
    Cuando usas delete en un puntero a la clase base (Animal*), si el destructor no es virtual, 
    solo se ejecuta el destructor de Animal, ignorando el destructor de Dog o Cat.
*/


