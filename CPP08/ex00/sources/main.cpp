#include <iostream>
#include "../includes/easyfind.hpp"

#define CONTAINER_SIZE 10
#define MAX 20
#define SEARCH 42

int main( void ) 
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                       Test with vector with INT"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << YELLOW << "Value to search: " << SEARCH << RESET << std::endl;
    std::cout << std::endl;
    
    std::vector<int> Vector;
    srand(time(NULL));
       
    for (int i = 0; i < CONTAINER_SIZE; i++) //random
    {
        const int value = rand() % MAX;
        Vector.push_back(value);
        std::cout << "Vector[" << i << "] = " << value << std::endl;
    }
    
    try
    {
        std::vector<int>::iterator it = easyFind(Vector, SEARCH);
        std::cout << GREEN << "\n✅ Found number: " << SEARCH  
                  << " at index: " << std::distance(Vector.begin(), it) << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                        Test with list with CHAR"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    char searchChar = 'a' + (rand() % 26); //to convert the 'int' to 'char'
    std::cout << YELLOW << "Char to search: " << searchChar << RESET << std::endl; //random
    std::cout << std::endl;
    
    std::list<int> myList;
    srand(time(NULL));
       
    for (int i = 0; i < CONTAINER_SIZE; i++) //random
    {
        const int value = 'a' + (rand() % 26); //to convert the 'int' to 'char'
        myList.push_back(value);
        std::cout << "List[" << i << "] = " << static_cast<char>(value) << std::endl;  //convert in char
    }
    
    try
    {
        std::list<int>::iterator it = easyFind(myList, searchChar);
        std::cout << GREEN << "\n✅ Found number: " << searchChar  
                  << " at index: " << std::distance(myList.begin(), it) << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return 0;
}

