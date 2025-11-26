#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 7
int main(int, char**)
{  
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                          TEST"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    std::cout << FORM << "\n✅ #1 creates an array using the template and a normal array,\n"
                    << "both with size 7, and asign random values to each array.\n" << RESET << std::endl;
    Array<int> nb(MAX_VAL);
    int* Mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        nb[i] = value;
        Mirror[i] = value;
    }
    
    //print
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Array1[" << i << "] = " << nb[i]
                  << " | Array2[" << i << "] = " << Mirror[i] << std::endl;
    }
    
    std::cout << FORM << "\n✅ #2 Using the Copy asigment operator and Copy constructor\n"
                    << "check that both arrays are equal.\n" << RESET << std::endl;
     
    //Copy assignment operator
    Array<int> copy;
    copy = nb;
    
    //print
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Copy[" << i << "] = " << copy[i]
                    << " | Original[" << i << "] = " << nb[i] << std::endl;
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (copy[i] != nb[i])
        {
            std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
            return 1;
        }
    }
    std::cerr << GREEN << "Both Arrays are equal!\n" << RESET << std::endl;
    
    //Copy constructor
    
    //print
    Array<int> newCopy(nb);
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "Copy[" << i << "] = " << newCopy[i]
                  << " | Original[" << i << "] = " << nb[i] << std::endl;
    } 
    
    //checks that both array are equal
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (newCopy[i] != nb[i])
        {
            std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
            return 1;
        }
    }
    std::cerr << GREEN << "Both Arrays are equal!" << RESET << std::endl;
    
    std::cout << FORM << "\n❌ #3 try to acces to in index -42 and 42 which are outside the limits\n" << RESET << std::endl;
    int index = -42;
    try
    {
        nb[index] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << index << e.what() << RESET << '\n';
    }
    index = 42;
    try
    {
        nb[index] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << index << e.what() << RESET << '\n';
    }
    
    std::cout << FORM << "\n✅ #4 re assigned values to the array\n" << RESET << std::endl; 
    for (int i = 0; i < MAX_VAL; i++)
    {
        nb[i] = rand();
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        //print
        std::cout << "numbers[" << i << "] = " << nb[i] << std::endl;
    }
    delete [] Mirror;
    return 0;
}