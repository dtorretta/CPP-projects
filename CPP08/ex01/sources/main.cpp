#include <iostream>
#include "../includes/Span.hpp"

int main( void ) 
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                              Basic test "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 vector created of size 5, filled with only one element\n" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);    
    sp.printElements();
    
    std::cout << FORM << "\n❌ #2 try to find the shortest and longest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << sp.shortestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try
    {
        std::cout << YELLOW << sp.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << FORM << "\n✅ #3 add the last 4 elements to fullfil the vector\n" << RESET << std::endl;
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);    
    sp.printElements();
    
    std::cout << FORM << "\n✅ #4 try to find the shortest and longest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << sp.shortestSpan() << RESET << std::endl;
        std::cout << YELLOW << sp.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
        std::cout << FORM << "\n❌ #5 try to add an additinal number\n" << RESET << std::endl;
    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                      test with rage of iterators"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 fill the vector\n" << RESET << std::endl;
    Span rage = Span(10);
    std::vector<int> vec; //temporal vector
    std::srand(std::time(0)); //srand(time(NULL));

    while (vec.size() < 10) //random numbers
    {
        int randomNum = std::rand() % 100;
        if (std::find(vec.begin(), vec.end(), randomNum) == vec.end()) // to avoid adding the same number twice
            vec.push_back(randomNum); //temporal vector
    }   

    rage.addRange(vec.begin(), vec.end()); //add multiple numbers to the Span in a single call  
    rage.printElements();

    std::cout << FORM << "\n✅ #4 find the shortest and longest span\n" << RESET << std::endl;
    try
    {   
        std::cout << YELLOW << rage.shortestSpan() << RESET << std::endl;
        std::cout << YELLOW << rage.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    vec.clear();
    
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 5"  << std::endl;
    std::cout << "                      test with 15000 numbers"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    Span bigSpan = Span(15000);
    std::srand(std::time(0)); // srand(time(NULL));

    while (vec.size() < 15000)
    {
        int randomNum = std::rand() % INT_MAX;
        if (std::find(vec.begin(), vec.end(), randomNum) == vec.end()) //to avoid adding the same number twice
            vec.push_back(randomNum);
    }   

    bigSpan.addRange(vec.begin(), vec.end()); //add multiple numbers to the Span in a single call   

    std::cout << FORM << "\n✅ #1 find the shortest and longest span\n" << RESET << std::endl;
    try
    {   
        std::cout << YELLOW << bigSpan.shortestSpan() << RESET << std::endl;
        std::cout << YELLOW << bigSpan.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cerr << std::endl;
    
    return 0;
}
