#include <iostream>
#include "Array.hpp"

#define SIZE 3
#define SIZE_2 2

int main(void)
{	
     std::cout	<< "Test canonical methods" << std::endl;
    Array<int> arrDefault;

    iter(arrDefault, &printElement);
    
    Array<int> arrInt(SIZE);


    for (unsigned int i = 0; i < SIZE; ++i)
    {
        arrInt[i] = i + 1;

    }
    iter(arrInt, &printElement);
Array<int> arrInt1(arrInt);
  Array<int> arrInt2(SIZE_2);
   for (unsigned int i = 0; i < SIZE_2; ++i)
    {
        arrInt2[i] = i + 100;
    }
    iter(arrInt2, &printElement);
    arrInt2 = arrInt;
    iter(arrInt2, &printElement);
std::cout	<< "Test copy constructur and assignment" << std::endl;
    arrInt[0] = 1000;
std::cout	<< "arrInt:" << std::endl;
iter(arrInt, &printElement);
std::cout	<< "arrInt1:" << std::endl;
iter(arrInt1, &printElement);
std::cout	<< "arrInt2:" << std::endl;
iter(arrInt2, &printElement);
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
