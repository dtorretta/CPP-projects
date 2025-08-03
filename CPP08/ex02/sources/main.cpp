#include <iostream>
#include "../includes/MutantStack.hpp"

int main( void ) 
{
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 1"  << std::endl;
    std::cout << "                            MutantStack test "  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5); //[5]
    mstack.push(17); //[5, 17]
    std::cout << FORM << "\n✅ #1 print the top int (last added)\n" << RESET << std::endl;
    std::cout << mstack.top() << std::endl;  //--> 17
    mstack.pop(); //[5]
    std::cout << FORM << "\n✅ #2 print the size\n" << RESET << std::endl;
    std::cout << mstack.size() << std::endl; //--> 1
    mstack.push(3); //[5, 3]
    mstack.push(5); //[5, 3, 5]
    mstack.push(737); //[5, 3, 5, 737]
    mstack.push(0); //[5, 3, 5, 737, 0]
    MutantStack<int>::iterator it = mstack.begin(); //*it = 5
    MutantStack<int>::iterator ite = mstack.end(); //*ite = 0
    ++it; //*it = 3
    --it; //*it = 5
    std::cout << FORM << "\n✅ #3 print the stack\n" << RESET << std::endl;
    while (it != ite)
    {
    std::cout << YELLOW << *it << RESET << std::endl; // --> [5, 3, 5, 737, 0]
    ++it;
    }
    
    std::cout << FORM << "\n✅ #4 creat a new stack as a copy of mstack\n" << RESET << std::endl;
    std::stack<int> s(mstack); //is std::stack and no MutantStack --> i cant use .begin nor .end
    
    std::stack<int> copy = s; //create a copy to print it by deleting each element
    while (!copy.empty()) // --> [0, 737, 5, 3, 5]
    {
        std::cout << copy.top() << std::endl; //top --> LIFO (Last In, First Out)
        copy.pop();
    }

    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 2"  << std::endl;
    std::cout << "                              List test"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    std::list<int> lstack;
    lstack.push_back(5); //[5]
    lstack.push_back(17); //[5, 17]
    std::cout << FORM << "\n✅ #1 print the top int (last added)\n" << RESET << std::endl;
    std::cout << lstack.back() << std::endl;  //--> 17
    lstack.pop_back(); //[5]
    std::cout << FORM << "\n✅ #2 print the size\n" << RESET << std::endl;
    std::cout << lstack.size() << std::endl; //--> 1
    lstack.push_back(3); //[5, 3]
    lstack.push_back(5); //[5, 3, 5]
    lstack.push_back(737); //[5, 3, 5, 737]
    lstack.push_back(0); //[5, 3, 5, 737, 0]
    std::list<int>::iterator listit = lstack.begin(); //*it = 5
    std::list<int>::iterator listite = lstack.end(); //*ite = 0
    ++listit; //*it = 3
    --listit; //*it = 5
    std::cout << FORM << "\n✅ #3 print the stack\n" << RESET << std::endl;
    while (listit != listite)
    {
        std::cout << YELLOW << *listit << RESET << std::endl; // --> [5, 3, 5, 737, 0]
        ++listit;
    }
    std::cout << "\n-----------------------------------------------------------------------------"  << std::endl;
    std::cout << "                                TEST 3"  << std::endl;
    std::cout << "                         reverse iterator test"  << std::endl;
    std::cout << "-----------------------------------------------------------------------------"  << std::endl;
    
    MutantStack<std::string> rstack;
    rstack.push("Hello"); //["hello"]
    rstack.push("World"); //["hello" "world"]
    rstack.push("!"); //["hello" "world" "!"]
    rstack.pop(); //["hello" "world"]
    std::cout << FORM << "\n✅ #1 print the top int (last added)\n" << RESET << std::endl;
    std::cout << rstack.top() << std::endl;  //--> world
    std::cout << FORM << "\n✅ #2 print the size\n" << RESET << std::endl;
    std::cout << rstack.size() << std::endl; //--> 2

    MutantStack<std::string>::rev_it rev_it = rstack.rbegin(); //*rev_it = world
    MutantStack<std::string>::rev_it rev_iter = rstack.rend(); //*ite = hello

    std::cout << FORM << "\n✅ #3 print the stack\n" << RESET << std::endl;
    while (rev_it != rev_iter)
    {
        std::cout << YELLOW << *rev_it << RESET << std::endl; // --> ["world" "hello"]
        ++rev_it;
    }
    return 0;
}
