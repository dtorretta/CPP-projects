#include <iostream>
#include "../includes/Iter.hpp"

//FX to increment value
template <typename T>  //no le puedo sacar esto porque lo necesita como parametro
void increase(T& val) //porque es un T y no un int?
{
    val++;
}

//FX to upper
void to_upper(std::string& str)
{
    for(size_t i = 0; i < str.size(); ++i)
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}


int main( void )
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                         basic test with INT "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;

    std::cout << FORM << "\n✅ #1 define array of int and PRINT\n" << RESET << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "original array: \n";
    for (int i = 0; i < 5; ++i)
		std::cout << YELLOW << arr[i] << RESET << std::endl;
	
	std::cout << FORM << "\n✅ #2 test INCREASE\n" << RESET << std::endl;
	::iter(arr, 5, ::increase<int>);
	std::cout << "after increase: \n";
	for (int i = 0; i < 5; ++i)
		std::cout << YELLOW << arr[i] << RESET << std::endl;

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                        basic test with STRING"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;

    std::cout << FORM << "\n✅ #1 test TO_UPPER\n" << RESET << std::endl;
    std::string array2[] = {"Hellow", "World!"};
    std::cout << "original array: \n";
    for (int i = 0; i < 2; ++i)
	    	std::cout << YELLOW << array2[i] << RESET << std::endl;
    std::cout << std::endl;
    
    ::iter(array2, 2, to_upper);  //no necesita ni los :: ni el <>
    std::cout << "after upper: \n";
    for (int i = 0; i < 2; ++i)
	 	std::cout << YELLOW << array2[i] << RESET << std::endl;

    std::cout << FORM << "\n✅ #2 test INCREASE\n" << RESET << std::endl;
    char array3[] = {'a', 'b', 'C'};
      std::cout << "original array: \n";
    for (int i = 0; i < 3; ++i)
	    	std::cout << YELLOW << array3[i] << RESET << std::endl;
    std::cout << std::endl;
    
    ::iter(array3, 3, ::increase<char>);
    std::cout << "after increase: \n";
    for (int i = 0; i < 3; ++i)
		std::cout << YELLOW << array3[i] << RESET << std::endl;
    std::cout << std::endl;
    
    return 0;
}
