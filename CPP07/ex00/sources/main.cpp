#include <iostream>
#include "../includes/Templates.hpp"

int main( void ) 
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                         basic test with INT "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 define 'a' and 'b'\n" << RESET << std::endl;
    int intA = 2;
    int intB = 3;
    std::cout << "Before swap: a = " << YELLOW << intA  << RESET << ", b = " << YELLOW << intB << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #2 Swap 'a' and 'b'\n" << RESET << std::endl;
    ::swap( intA, intB );
    std::cout << "After swap: a = " << YELLOW << intA << RESET << ", b = " << YELLOW << intB << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #3 Test MIN and MAX\n" << RESET << std::endl;
    std::cout << "min(a, b) = " << YELLOW << ::min( intA, intB ) << RESET << std::endl;
    std::cout << "max(a, b) = " << YELLOW << ::max( intA, intB ) << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #4 Test MIN and MAX with same values\n" << RESET << std::endl;
    int intC = 42;
    int intD = 42;
    std::cout << "c = " << YELLOW << intC << RESET << " adress: " << YELLOW << &intC << RESET << 
                ", d = " << YELLOW << intD << RESET << " adress: " << YELLOW << &intD << RESET << std::endl;
    
    int& resultmin = ::min( intC, intD );
    std::cout << "min(c, d) = " << YELLOW << &resultmin << RESET << std::endl;
    int& resultmax = ::max( intC, intD );
    std::cout << "max(c, d) = " << YELLOW << &resultmax << RESET << std::endl;
    
    
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                        basic test with STRING"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 define 'c' and 'd'\n" << RESET << std::endl;
    std::string s1 = "hello";
    std::string s2 = "world!";
    std::cout << "Before swap: c = " << YELLOW << s1 << RESET << ", d = " << YELLOW << s2 << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #2 Swap a nd b\n" << RESET << std::endl;
    ::swap(s1, s2);
    std::cout << "After swap: c = " << YELLOW << s1 << RESET << ", d = " << YELLOW << s2 << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #3 Test MIN and MAX\n" << RESET << std::endl;
    std::cout << "min(c, d) = " << YELLOW << ::min( s1, s2 ) << RESET << std::endl;
    std::cout << "max(c, d) = " << YELLOW << ::max( s1, s2 ) << RESET << std::endl;
    

    std::cout << FORM << "\n✅ #4 Test MIN and MAX with same values\n" << RESET << std::endl;
    std::string s3 = "hello";
    std::string s4 = "hello";
    std::cout << "c = " << YELLOW << s3 << RESET << " adress: " << YELLOW << &s3 << RESET << 
                ", d = " << YELLOW << s4 << RESET << " adress: " << YELLOW << &s4 << RESET << std::endl;

    std::string& resultstringmin = ::min( s3, s4 );
    std::cout << "min(c, d) = " << YELLOW << &resultstringmin << RESET << std::endl;
    std::string& resultstringmax = ::max( s3, s4 );
    std::cout << "max(c, d) = " << YELLOW << &resultstringmax << RESET << std::endl;


    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 3"  << std::endl;
    std::cout << "                        basic test with FLOAT "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::cout << FORM << "\n✅ #1 define 'a' and 'b'\n" << RESET << std::endl;
    float floatA = -42.2;
    float floatB = 10.6;
    std::cout << "Before swap: a = " << YELLOW << floatA << RESET << ", b = " << YELLOW << floatB << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #2 Swap 'a' and 'b'\n" << RESET << std::endl;
    ::swap( floatA, floatB );
    std::cout << "After swap: a = " << YELLOW << floatA << RESET << ", b = " << YELLOW << floatB << RESET << std::endl;
    
    std::cout << FORM << "\n✅ #3 Test MIN and MAX\n" << RESET << std::endl;
    std::cout << "min(a, b) = " << YELLOW << ::min( floatA, floatB ) << RESET << std::endl;
    std::cout << "max(a, b) = " << YELLOW << ::max( floatA, floatB ) << RESET << std::endl;
       
    std::cout << FORM << "\n✅ #4 Test MIN and MAX with same values\n" << RESET << std::endl;
    float floatC = -66.6;
    float floatD = -66.6;
    std::cout << "c = " << YELLOW << floatC << RESET << " adress: " << YELLOW << &floatC << RESET << 
                ", d = " << YELLOW << floatD << RESET << " adress: " << YELLOW << &floatD << RESET << std::endl;
       
    float& resultfloatmin = ::min( floatC, floatD );
    std::cout << "min(c, d) = " << YELLOW << &resultfloatmin << RESET << std::endl;    
    float& resultfloatmax =  ::max( floatC, floatD );
    std::cout << "max(c, d) = " << YELLOW << &resultfloatmax << RESET << std::endl;
    

    return 0;
}

/*

a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2

*/