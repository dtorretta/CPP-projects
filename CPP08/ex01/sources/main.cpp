#include <iostream>
#include "../includes/Span.hpp"

int main( void ) 
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                              Basic test "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 fill the vector\n" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    sp.printElements();
    
    std::cout << FORM << "\n✅ #2 find shortest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << sp.shortestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << FORM << "\n✅ #3 find longest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << sp.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                        Test error NoSpanFound"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 fill the vector\n" << RESET << std::endl;
    Span error2 = Span(1);
    error2.addNumber(42);
    
    error2.printElements();
    
    std::cout << FORM << "\n❌ #2 find shortest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << error2.shortestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << FORM << "\n❌ #3 find longest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << error2.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 3"  << std::endl;
    std::cout << "                       Test error NoMoreSpace"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 fill the vector\n" << RESET << std::endl;
    Span error1 = Span(3);
    error1.addNumber(6);
    error1.addNumber(3);
    error1.addNumber(17);
    
    error1.printElements();
    
    std::cout << FORM << "\n❌ #2 try to add an additinal number\n" << RESET << std::endl;
    try
    {
        error1.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 4"  << std::endl;
    std::cout << "                      test with rage of iterators"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 fill the vector\n" << RESET << std::endl;
    Span rage = Span(10);
    std::vector<int> vec; //un vector temporal
    std::srand(std::time(0)); // srand(time(NULL));

    while (vec.size() < 10)
    {
        int randomNum = std::rand() % 100;
        if (std::find(vec.begin(), vec.end(), randomNum) == vec.end()) // Verificamos si ya existe en el vector
            vec.push_back(randomNum);
    }   

    rage.addRange(vec.begin(), vec.end()); //a;adimos a rage los int del vector temporal    
    rage.printElements();

    std::cout << FORM << "\n✅ #2 find shortest span\n" << RESET << std::endl;
    try
    {   
        std::cout << YELLOW << rage.shortestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << FORM << "\n✅ #3 find longest span\n" << RESET << std::endl;
    try
    {
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
    //std::vector<int> vec; //un vector temporal
    std::srand(std::time(0)); // srand(time(NULL));

    while (vec.size() < 15000)
    {
        int randomNum = std::rand() % INT_MAX;
        if (std::find(vec.begin(), vec.end(), randomNum) == vec.end()) // Verificamos si ya existe en el vector
            vec.push_back(randomNum);
    }   

    bigSpan.addRange(vec.begin(), vec.end()); //a;adimos a bigspan los int del vector temporal    

    std::cout << FORM << "\n✅ #1 find shortest span\n" << RESET << std::endl;
    try
    {   
        std::cout << YELLOW << bigSpan.shortestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << FORM << "\n✅ #2 find longest span\n" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << bigSpan.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cerr << std::endl;
    return 0;
}
