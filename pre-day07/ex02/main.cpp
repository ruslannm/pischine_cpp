#include <iostream>
#include "Array.hpp"

#define SIZE 3
#define SIZE_2 2

int main(void)
{	
     std::cout	<< "Test canonical methods" << std::endl;
    Array<int> arrDefault;
    std::cout << "arrDefault " << arrDefault << std::endl;
  
    Array<int> arrInt(SIZE);
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        arrInt[i] = i + 1;

    }
    std::cout << "arrInt " << arrInt << std::endl;
    Array<int> arrInt1(arrInt);
    std::cout << "arrInt1 " << arrInt1 << std::endl;
    Array<int> arrInt2(SIZE_2);
    for (unsigned int i = 0; i < SIZE_2; ++i)
    {
        arrInt2[i] = i + 100;
    }
    std::cout << "arrInt2 " << arrInt2 << std::endl;
    arrInt2 = arrInt;
    std::cout << "arrInt2 " << arrInt2 << std::endl;
    arrInt[0] = 1000;
std::cout << "arrInt" << arrInt << std::endl;
std::cout << "arrInt1" << arrInt1 << std::endl;
std::cout << "arrInt2" << arrInt2 << std::endl;
std::cout	<< "Test exceptions" << std::endl;
    try
    {
        arrInt[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    try
    {
        arrInt[SIZE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
