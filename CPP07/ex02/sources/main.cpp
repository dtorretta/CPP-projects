#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 7 //from subject 750 then change to 7 to test it
int main(int, char**)
{
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 1"  << std::endl;
    std::cout << "                      From subject"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    //#1 creates an array using the template with size 750
    Array<int> numbers(MAX_VAL);
    
    //#2 creates a normal array with size 750
    int* mirror = new int[MAX_VAL];
    
    //#3 asign random values to each array
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    //#4 check the correct function os the copy asigment operators
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    //#5 checks that both array are equal
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    //#6 try to acces to in index -2 which is outside the limits
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //#7 try to acces to in index 750 which is outside the limits
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //#8 re assigned values to the array
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    
    std::cout << "\n--------------------------------------------------------------"  << std::endl;
    std::cout << "                         TEST 2"  << std::endl;
    std::cout << "                    array with 7 elements"  << std::endl;
    std::cout << "--------------------------------------------------------------"  << std::endl;
    std::cout << FORM << "\n✅ #1 creates an array using the template and a normal array, both with size 7.\n" << RESET << std::endl;
    Array<int> nb(7);
    int* Mirror = new int[7];
    
    std::cout << FORM << "\n✅ #2 asign random values to each array \n" << RESET << std::endl;
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
    {
        const int value = rand();
        nb[i] = value;
        Mirror[i] = value;
    }
    for (int i = 0; i < 7; i++)
    {
        std::cout << "numbers[" << i << "] = " << nb[i]
                  << " | mirror[" << i << "] = " << Mirror[i] << std::endl;
    }
    
    std::cout << FORM << "\n✅ #3 check the correct function os the copy asigment operators\n" << RESET << std::endl;
    {   
        std::cout << YELLOW << "Copy assignment operator:" << RESET << std::endl;
        Array<int> copy = nb;
        for (int i = 0; i < 7; i++)
        {
            std::cout << "Copy[" << i << "] = " << copy[i]
                      << " | Original[" << i << "] = " << nb[i] << std::endl;
        }
    
        std::cout << YELLOW << "\nCopy assignment operator:" << RESET << std::endl;
        Array<int> newCopy(copy);
        for (int i = 0; i < 7; i++)
        {
            std::cout << "Copy[" << i << "] = " << newCopy[i]
                      << " | Original[" << i << "] = " << copy[i] << std::endl;
        }
    }
    
    std::cout << FORM << "\n✅ #4 checks that both array are equal.\n" << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != nb[i])
        {
            std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
            return 1;
        }
    }
    std::cerr << GREEN << "For loop ended witout errors. Both Arrays are equal!" << RESET << std::endl;
    
    std::cout << FORM << "\n❌ #5 try to acces to in index -42 which is outside the limits\n" << RESET << std::endl;
    try
    {
        nb[-42] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    std::cout << FORM << "\n❌ #6 try to acces to in index 7 which is outside the limits\n" << RESET << std::endl;
    try
    {
        nb[7] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    
    std::cout << FORM << "\n✅ #7 re assigned values to the array\n" << RESET << std::endl; 
    for (int i = 0; i < 7; i++)
    {
        nb[i] = rand();
    }
    for (int i = 0; i < 7; i++)
    {
        std::cout << "numbers[" << i << "] = " << nb[i] << std::endl;
    }
    delete [] Mirror;
    return 0;
}