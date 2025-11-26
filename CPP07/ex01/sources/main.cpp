#include <iostream>
#include "../includes/Iter.hpp"

int main( void )
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                         basic test with INT "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;

    std::cout << FORM << "\n✅ #1 define array of int and test PRINTELEMENT (const)\n" << RESET << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    
    std::cout << "original array: \n";
    iter(arr, 5, printElement<int>);
	  std::cout << std::endl;
	  
  	std::cout << FORM << "\n✅ #2 test INCREASE\n" << RESET << std::endl;	
  	std::cout << "after increase: \n";
  	iter(arr, 5, increase<int>);
  	iter(arr, 5, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                        basic test with STRING"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;

    std::cout << FORM << "\n✅ #1 test UPPER\n" << RESET << std::endl;
    std::string array2[] = {"Hello ", "World!"};
    std::cout << "original array: \n";
    iter(array2, 2, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << "\nafter upper: \n";
    iter(array2, 2, upper);  //no necesita el <> --> usamos '<>' para definir el tipo
    iter(array2, 2, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << FORM << "\n✅ #2 test INCREASE\n" << RESET << std::endl;
    char array3[] = {'a', 'b', 'C'};
    std::cout << "original array: \n";
    iter(array3, 3, printElement<char>);
    std::cout << std::endl;
        
    std::cout << "\nafter increase: \n";
    iter(array3, 3, increase<char>);
    iter(array3, 3, printElement<char>);
    std::cout << std::endl;
    
    return 0;
}
